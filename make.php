<?php

use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Finder\Finder;
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

$finder = new Finder();

$makeFiles = $finder->files()->name('*.make')->depth(1)->in($src);

$profiles = array();

foreach ($makeFiles as $makeFile) {
  $profiles[] = $makeFile->getPathInfo()->getFilename();
}

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

  if ($make->run(
      function ($type, $buffer) {
        echo $buffer;
      }
    ) > 0
  ) {
    throw new Exception('Failed to run command: ' . $make->getCommandLine());
  }

  $filesets = array(
    $profileSrc => array(
      $profile . '.info',
      $profile . '.install',
      $profile . '.profile',
      'README.md',
      'CHANGELOG.md',
    ),
    $src => array('cambridge_base.inc'),
    __DIR__ => array('LICENSE.txt'),
  );

  $directorySets = array(
    $profileSrc => array(
      'doc',
    ),
  );

  foreach ($filesets as $fileDir => $files) {
    foreach ($files as $file) {
      $fs->copy($fileDir . '/' . $file, $build . '/src/' . $profile . '/' . $file);
    }
  }

  foreach ($directorySets as $directoryDir => $directories) {
    foreach ($directories as $directory) {
      $fs->mirror($directoryDir . '/' . $directory, $build . '/src/' . $profile . '/' . $directory);
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
