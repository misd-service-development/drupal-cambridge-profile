University of Cambridge Drupal 7 install profiles
=================================================

There are two different install profiles available:

- **cambridge_lite**

  In the lite profile the University of Cambridge theme is enabled and a few standard pieces are set up (eg images styles, front-page carousel).

  This profile is useful if you would like full control over how your Drupal site is put together.

- **cambridge**

  The full profile contains all the features of the lite profile, plus additions that helps you to quickly get going: various common modules are enabled and pre-configured to sensible defaults, while other common-but-not-always-used modules are bundled but not enabled.

  This profile is useful if you don't mind following established patterns when putting your Drupal site together.

Build process
-------------

### Installing dependencies

#### *nix

The build process requires [Composer](http://getcomposer.org/). You can install this by executing:

    curl -sS https://getcomposer.org/installer | php

Then install the dependencies.

    php composer.phar install

#### Windows

Use the [Windows installer](http://getcomposer.org/doc/00-intro.md#installation-windows) to make Composer globally available.

Then install the dependencies:

    composer install

Finally, you'll also need to execute:

    git apply drush_windows_git_apply.patch

This fixes a long-term bug in Drush that stops patches from being applied.

### Building the profiles

To build the profiles simply execute:

    php make.php

The `build` folder will now contain distributable ZIP/TAR files for each profile, as well as source directories.

To build a single profile you can just pass the profile's name:

    php make.php cambridge_lite
