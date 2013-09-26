<?php

use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Process\Process;

require_once __DIR__ . '/vendor/autoload.php';

umask(0002);

$fs = new Filesystem();

$src = __DIR__ . '/src';
$build = __DIR__ . '/build';
$drush = __DIR__ . '/vendor/drush/drush/drush.php';
$tmp = sys_get_temp_dir() . '/cambridge-drupal-' . uniqid();

$fs->remove($build);

$arguments = array_slice($argv, 1);

$profiles = array(
  'cambridge',
  'cambridge_lite',
);

if (count($arguments) > 0) {
  foreach ($arguments as $argument) {
    if (FALSE === in_array($argument, $profiles)) {
      throw new Exception('Unknown profile \'' . $argument . '\'');
    }
  }

  $profiles = $arguments;
}

foreach ($profiles as $profile) {
  $profileSrc = $src . '/' . $profile;

  $info = parse_ini_file($profileSrc . '/' . $profile . '.info');

  $make = new Process('php ' . $drush . ' make --no-core --contrib-destination=. ' . $profileSrc . '/' . $profile . '.make ' . $tmp . '/' . $profile);

  $make->setTimeout(NULL);

  if ($make->run() > 0) {
    throw new Exception('Failed to run command: ' . $make->getCommandLine());
  }

  $filesets = array(
    $profileSrc => array(
      $profile . '.info',
      $profile . '.install',
      $profile . '.profile'
    ),
    $src => array('cambridge_base.inc'),
    __DIR__ => array('LICENSE.txt'),
  );

  foreach ($filesets as $fileDir => $files) {
    foreach ($files as $file) {
      $fs->copy($fileDir . '/' . $file, $build . '/src/' . $profile . '/' . $file);
    }
  }

  $fs->mirror($tmp . '/' . $profile, $build . '/src/' . $profile);

  $tar = new PharData($tmp . '/' . $profile . '.tar');
  $tar->buildFromDirectory($build . '/src/' . $profile);
  $tar->compress(Phar::GZ);

  $zip = new PharData($tmp . '/' . $profile . '.zip');
  $zip->buildFromDirectory($build . '/src/' . $profile);

  $fs->copy($tmp . '/' . $profile . '.tar.gz', $build . '/dist/' . $profile . '-' . $info['version'] . '.tar.gz');
  $fs->copy($tmp . '/' . $profile . '.zip', $build . '/dist/' . $profile . '-' . $info['version'] . '.zip');
}
