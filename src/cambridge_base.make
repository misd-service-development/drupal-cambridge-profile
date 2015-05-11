api = 2
core = 7.x

defaults[projects][subdir] = "contrib"

; theme

projects[cambridge_theme][type] = "theme"
projects[cambridge_theme][download][type] = "file"
projects[cambridge_theme][download][url] = "https://github.com/misd-service-development/drupal-cambridge-theme/archive/7.x-1.3.tar.gz"
projects[cambridge_theme][patch][] = "https://github.com/misd-service-development/drupal-cambridge-theme/commit/c1056076902e87e6eef838adb202321775b2b310.patch"
projects[cambridge_theme][subdir] = ""

; contrib

projects[ctools] = "1.7"
projects[features][version] = "2.5"
projects[features][subdir] = "contrib"
projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6241365/raw/fccdba35efbd5ec106d8b92a8af98f71172e1870/imagecrop_query_string.patch"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6351355/raw/a34c91e4480aa7c4c0b79644e13aeeec914c1726/imagecrop_theme.patch"
projects[libraries] = "2.2"
projects[link][version] = "1.3"
projects[link][patch][] = "http://cgit.drupalcode.org/link/patch/?id=b373ad65850947c2a69a15be3587ebb22b107efc"
projects[link][patch][] = "http://cgit.drupalcode.org/link/patch/?id=2e82084e104ed8696c1fda15f001bea25ededf03"
projects[menu_block] = "2.5"
projects[menu_firstchild][version] = "1.1"
projects[menu_firstchild][patch][] = "http://www.drupal.org/files/issues/pathauto-token-2295059-1.patch"
projects[pathauto] = "1.2"
projects[pathauto_persist] = "1.3"
projects[raven][type] = "module"
projects[raven][download][type] = "file"
projects[raven][download][url] = "https://github.com/misd-service-development/drupal-raven/archive/7.x-1.3.tar.gz"
projects[raven][patch][] = "https://github.com/misd-service-development/drupal-raven/commit/cfff4cbf50a03ec3806da4a9ce11c29773fbc0eb.patch"
projects[token] = "1.6"
projects[views] = "3.10"

; features

projects[cambridge_carousel][type] = "module"
projects[cambridge_carousel][download][type] = "file"
projects[cambridge_carousel][download][url] = "https://github.com/misd-service-development/drupal-feature-carousel/archive/7.x-1.0.tar.gz"
projects[cambridge_carousel][subdir] = "features"

projects[cambridge_image_styles][type] = "module"
projects[cambridge_image_styles][download][type] = "file"
projects[cambridge_image_styles][download][url] = "https://github.com/misd-service-development/drupal-feature-image-styles/archive/7.x-1.0.tar.gz"
projects[cambridge_image_styles][patch][] = "https://github.com/thewilkybarkid/drupal-feature-image-styles/commit/8e581c3591702fbff8481a8c0c7e94a68b58cbea.patch"
projects[cambridge_image_styles][subdir] = "features"

projects[cambridge_link][type] = "module"
projects[cambridge_link][download][type] = "file"
projects[cambridge_link][download][url] = "https://github.com/misd-service-development/drupal-feature-link/archive/7.x-1.0.tar.gz"
projects[cambridge_link][subdir] = "features"

projects[cambridge_teasers][type] = "module"
projects[cambridge_teasers][download][type] = "file"
projects[cambridge_teasers][download][url] = "https://github.com/misd-service-development/drupal-feature-teasers/archive/7.x-1.3.tar.gz"
projects[cambridge_teasers][subdir] = "features"
