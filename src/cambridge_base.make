api = 2
core = 7.x

defaults[projects][subdir] = "contrib"

; theme

projects[cambridge_theme][type] = "theme"
projects[cambridge_theme][download][type] = "file"
projects[cambridge_theme][download][url] = "https://github.com/misd-service-development/drupal-cambridge-theme/archive/7.x-1.1.tar.gz"
projects[cambridge_theme][subdir] = ""

; contrib

projects[ctools] = "1.4"
projects[features][version] = "2.0"
projects[features][subdir] = "contrib"
projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6241365/raw/fccdba35efbd5ec106d8b92a8af98f71172e1870/imagecrop_query_string.patch"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6351355/raw/a34c91e4480aa7c4c0b79644e13aeeec914c1726/imagecrop_theme.patch"
projects[libraries] = "2.2"
projects[link] = "1.2"
projects[menu_block] = "2.4"
projects[menu_firstchild] = "1.1"
projects[pathauto] = "1.2"
projects[raven][type] = "module"
projects[raven][download][type] = "file"
projects[raven][download][url] = "https://github.com/misd-service-development/drupal-raven/archive/7.x-1.1.tar.gz"
projects[token] = "1.5"
projects[views] = "3.8"

; features

projects[cambridge_carousel][type] = "module"
projects[cambridge_carousel][download][type] = "file"
projects[cambridge_carousel][download][url] = "https://github.com/misd-service-development/drupal-feature-carousel/archive/7.x-1.0.tar.gz"
projects[cambridge_carousel][subdir] = "features"

projects[cambridge_image_styles][type] = "module"
projects[cambridge_image_styles][download][type] = "file"
projects[cambridge_image_styles][download][url] = "https://github.com/misd-service-development/drupal-feature-image-styles/archive/7.x-1.0.tar.gz"
projects[cambridge_image_styles][subdir] = "features"

projects[cambridge_link][type] = "module"
projects[cambridge_link][download][type] = "file"
projects[cambridge_link][download][url] = "https://github.com/misd-service-development/drupal-feature-link/archive/7.x-1.0.tar.gz"
projects[cambridge_link][subdir] = "features"

projects[cambridge_teasers][type] = "module"
projects[cambridge_teasers][download][type] = "file"
projects[cambridge_teasers][download][url] = "https://github.com/misd-service-development/drupal-feature-teasers/archive/7.x-1.3.tar.gz"
projects[cambridge_teasers][subdir] = "features"
