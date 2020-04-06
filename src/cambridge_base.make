api = 2
core = 7.x

defaults[projects][subdir] = "contrib"

; theme

projects[cambridge_theme][type] = "theme"
projects[cambridge_theme][version] = "1.12"
projects[cambridge_theme][download][type] = "file"
projects[cambridge_theme][download][url] = "https://github.com/misd-service-development/drupal-cambridge-theme/archive/7.x-1.12.tar.gz"
projects[cambridge_theme][subdir] = ""

; contrib

projects[ctools] = "1.15"
projects[features][version] = "2.11"
projects[features][subdir] = "contrib"

projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][type] = "module"
projects[imagecrop][download][type] = "file"
projects[imagecrop][download][url] = "https://gitlab.developers.cam.ac.uk/uis/webcms/drupal-modules/imagecrop/-/archive/1.0-rc3/imagecrop-1.0-rc3.tar.gz"
projects[jquery_update] = "2.7"
projects[libraries] = "2.5"
projects[link][version] = "1.7"
projects[menu_block] = "2.8"
projects[menu_firstchild][patch][] = "http://www.drupal.org/files/issues/pathauto-token-2295059-1.patch"
projects[pathauto] = "1.3"
;projects[pathauto_persist] = "1.4"
projects[raven][type] = "module"
projects[raven][download][type] = "file"
projects[raven][download][url] = "https://gitlab.developers.cam.ac.uk/uis/webcms/drupal-modules/raven/-/archive/v1.6.2/raven-v1.6.2.tar.gz"
;projects[raven][download][url] = "https://github.com/misd-service-development/drupal-raven/archive/7.x-1.3.tar.gz"
;projects[raven][patch][] = "https://github.com/misd-service-development/drupal-raven/commit/cfff4cbf50a03ec3806da4a9ce11c29773fbc0eb.patch"
projects[token] = "1.7"
projects[views] = "3.24"

; features

projects[cambridge_carousel][type] = "module"
projects[cambridge_carousel][download][type] = "file"
projects[cambridge_carousel][download][url] = "https://github.com/misd-service-development/drupal-feature-carousel/archive/7.x-1.1.tar.gz"
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
projects[cambridge_teasers][download][url] = "https://github.com/misd-service-development/drupal-feature-teasers/archive/7.x-1.6.tar.gz"
projects[cambridge_teasers][subdir] = "features"

projects[simple_lookup][type] = "module"
projects[simple_lookup][download][type] = "file"
projects[simple_lookup][download][url] = "https://gitlab.developers.cam.ac.uk/uis/webcms/drupal-modules/simple_lookup/-/archive/1.1.1/simple_lookup-1.1.1.tar.gz"
projects[simple_lookup][subdir] = "custom"
