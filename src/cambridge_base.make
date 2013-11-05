api = 2
core = 7.x

defaults[projects][subdir] = "contrib"

; theme

projects[cambridge_theme][type] = "theme"
projects[cambridge_theme][download][type] = "file"
projects[cambridge_theme][download][url] = "https://github.com/misd-service-development/drupal-cambridge-theme/archive/master.tar.gz"
projects[cambridge_theme][subdir] = ""

; contrib

projects[ctools] = "1.3"
projects[features][version] = "2.0-rc5"
projects[features][subdir] = "contrib"
projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][subdir] = "patched"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6241365/raw/fccdba35efbd5ec106d8b92a8af98f71172e1870/imagecrop_query_string.patch"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6351355/raw/a34c91e4480aa7c4c0b79644e13aeeec914c1726/imagecrop_theme.patch"
projects[libraries] = "2.1"
projects[link] = "1.1"
projects[menu_block] = "2.3"
projects[pathauto] = "1.2"
projects[raven][type] = "module"
projects[raven][download][type] = "file"
projects[raven][download][url] = "https://github.com/misd-service-development/drupal-raven/archive/master.tar.gz"
projects[token] = "1.5"
projects[views] = "3.7"

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

projects[cambridge_news][type] = "module"
projects[cambridge_news][download][type] = "file"
projects[cambridge_news][download][url] = "https://github.com/misd-service-development/drupal-feature-news/archive/master.tar.gz"
projects[cambridge_news][subdir] = "features"

projects[cambridge_related_links][type] = "module"
projects[cambridge_related_links][download][type] = "file"
projects[cambridge_related_links][download][url] = "https://github.com/misd-service-development/drupal-feature-related-links/archive/master.tar.gz"
projects[cambridge_related_links][subdir] = "features"

projects[cambridge_teasers][type] = "module"
projects[cambridge_teasers][download][type] = "file"
projects[cambridge_teasers][download][url] = "https://github.com/misd-service-development/drupal-feature-teasers/archive/7.x-1.0.tar.gz"
projects[cambridge_teasers][subdir] = "features"
