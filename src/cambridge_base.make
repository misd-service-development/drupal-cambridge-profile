api = 2
core = 7.x

defaults[projects][subdir] = "contrib"

; theme

projects[cambridge_theme][type] = "theme"
projects[cambridge_theme][version] = "1.11"
projects[cambridge_theme][download][type] = "file"
projects[cambridge_theme][download][url] = "https://github.com/misd-service-development/drupal-cambridge-theme/archive/7.x-1.11.tar.gz"
projects[cambridge_theme][subdir] = ""

; contrib

projects[ctools] = "1.15"
projects[features][version] = "2.11"
projects[features][subdir] = "contrib"
projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6241365/raw/fccdba35efbd5ec106d8b92a8af98f71172e1870/imagecrop_query_string.patch"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6351355/raw/a34c91e4480aa7c4c0b79644e13aeeec914c1726/imagecrop_theme.patch"
projects[libraries] = "2.5"
projects[link][version] = "1.6"
;projects[link][patch][] = "https://www.drupal.org/files/issues/revert-url-validation-2666912.patch"
;projects[link][patch][] = "https://www.drupal.org/files/issues/2018-08-10/link-revert_url_validation-2666912_2.patch"
;We need the patch below but it isn't compatible with version 1.6, which is a security fix so that takes priority.
;projects[link][patch][] = "https://raw.githubusercontent.com/misd-service-development/drupal-patches/master/link-revert_url_validation-2666912_2_modified.patch"

projects[menu_block] = "2.8"
projects[menu_firstchild][version] = "1.1"
projects[menu_firstchild][patch][] = "http://www.drupal.org/files/issues/pathauto-token-2295059-1.patch"
projects[pathauto] = "1.3"
;projects[pathauto_persist] = "1.4"
projects[raven][type] = "module"
projects[raven][download][type] = "file"
projects[raven][download][url] = "https://github.com/misd-service-development/drupal-raven/archive/7.x-1.3.tar.gz"
projects[raven][patch][] = "https://github.com/misd-service-development/drupal-raven/commit/cfff4cbf50a03ec3806da4a9ce11c29773fbc0eb.patch"
projects[token] = "1.7"
projects[views] = "3.20"

; features

projects[cambridge_carousel][type] = "module"
projects[cambridge_carousel][download][type] = "file"
projects[cambridge_carousel][download][url] = "https://github.com/misd-service-development/drupal-feature-carousel/archive/7.x-1.0.tar.gz"
projects[cambridge_carousel][subdir] = "features"

projects[cambridge_image_styles][type] = "module"
projects[cambridge_image_styles][download][type] = "file"
projects[cambridge_image_styles][download][url] = "https://github.com/misd-service-development/drupal-feature-image-styles/archive/7.x-1.1.tar.gz"
projects[cambridge_image_styles][subdir] = "features"

projects[cambridge_link][type] = "module"
projects[cambridge_link][download][type] = "file"
projects[cambridge_link][download][url] = "https://github.com/misd-service-development/drupal-feature-link/archive/7.x-1.0.tar.gz"
projects[cambridge_link][subdir] = "features"

projects[cambridge_teasers][type] = "module"
projects[cambridge_teasers][download][type] = "file"
projects[cambridge_teasers][download][url] = "https://github.com/misd-service-development/drupal-feature-teasers/archive/7.x-1.4.tar.gz"
projects[cambridge_teasers][subdir] = "features"
