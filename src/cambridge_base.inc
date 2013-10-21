<?php

/**
 * @file
 * Base functions for the University of Cambridge installation profiles.
 */

/**
 * Perform actions to set up the site for the profiles.
 */
function cambridge_base_install() {
  // Features aren't normally available until after hook_install, so make them available now.
  features_revert();

  // Add text formats.

  $filtered_html_format = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $filtered_html_format = (object) $filtered_html_format;
  filter_format_save($filtered_html_format);

  $full_html_format = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $full_html_format = (object) $full_html_format;
  filter_format_save($full_html_format);

  // Add content types.

  $types = array(
    array(
      'type' => 'page',
      'name' => st('Basic Page'),
      'base' => 'node_content',
      'description' => st("Use <em>basic pages</em> for your static content, such as an 'About us' page."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
    ),
    array(
      'type' => 'link',
      'name' => st('Link'),
      'base' => 'node_content',
      'description' => st("Use <em>link</em> to add custom links to lists, such as teasers or carousels."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
      'title_label' => 'Administrative title',
    ),
  );

  foreach ($types as $type) {
    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type);

    // Not promoted to front page.
    variable_set('node_options_' . $type->type, array('status'));

    // Don't display date and author information.
    variable_set('node_submitted_' . $type->type, FALSE);
  }

  $instances = array(
    array(
      'entity_type' => 'node',
      'bundle' => 'page',
      'field_name' => 'field_image',
      'label' => st('Image'),
      'cardinality' => 1,
      'type' => 'field_image',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'imagecrop' => array(
          'carousel' => 'carousel',
          'inline' => 'inline',
          'leading' => 'leading',
          'sidebar_teaser' => 'sidebar_teaser'
        ),
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '885x432',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'leading', 'image_link' => ''),
          'weight' => -1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => 'content'),
          'weight' => -1,
        ),
        'carousel_item' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'carousel', 'image_link' => 'content'),
          'weight' => -1,
        ),
        'news_listing_item' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'vertical_teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => 'content'),
          'weight' => -1,
        ),
        'sidebar_teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'sidebar_teaser', 'image_link' => 'content'),
          'weight' => -1,
        ),
      ),
    ),
    array(
      'entity_type' => 'node',
      'bundle' => 'page',
      'field_name' => 'field_related_links',
      'label' => st('Related links'),
      'cardinality' => -1,
      'type' => 'field_related_links',
      'settings' => array(
        'title' => 'required',
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    array(
      'entity_type' => 'node',
      'bundle' => 'link',
      'field_name' => 'field_image',
      'label' => st('Image'),
      'required' => 1,
      'cardinality' => 1,
      'type' => 'field_image',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'imagecrop' => array(
          'carousel' => 'carousel',
          'inline' => 'inline',
          'leading' => 0,
          'sidebar_teaser' => 'sidebar_teaser'
        ),
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '885x432',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => '', 'image_link' => ''),
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => ''),
          'weight' => -1,
        ),
        'carousel_item' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'carousel', 'image_link' => ''),
          'weight' => -1,
        ),
        'news_listing_item' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'vertical_teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => ''),
          'weight' => -1,
        ),
        'sidebar_teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'sidebar_teaser', 'image_link' => ''),
          'weight' => -1,
        ),
      ),
    ),
    array(
      'entity_type' => 'node',
      'bundle' => 'link',
      'field_name' => 'field_link',
      'label' => st('Link'),
      'required' => 1,
      'cardinality' => 1,
      'type' => 'field_carousel_caption',
      'settings' => array(
        'title' => 'optional',
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'link_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'link_default',
          'weight' => 1,
        ),
        'carousel_item' => array(
          'label' => 'hidden',
          'type' => 'link_default',
          'weight' => 1,
        ),
        'news_listing_item' => array(
          'label' => 'hidden',
          'type' => 'link_defualt',
          'weight' => 1,
        ),
        'vertical_teaser' => array(
          'label' => 'hidden',
          'type' => 'link_default',
          'weight' => 1,
        ),
        'sidebar_teaser' => array(
          'label' => 'hidden',
          'type' => 'link_default',
          'weight' => 1,
        ),
      ),
    ),
  );

  foreach ($instances as $instance) {
    field_create_instance($instance);
  }

  foreach ($types as $type) {
    // Make sure the body appears trimmed in teasers.

    $instance = field_info_instance('node', 'body', $type['type']);

    $instance['display']['news_listing_item'] = array('label' => 'hidden', 'type' => 'text_summary_or_trimmed');
    $instance['display']['vertical_teaser'] = array('label' => 'hidden', 'type' => 'text_summary_or_trimmed');
    $instance['display']['sidebar_teaser'] = array('label' => 'hidden', 'type' => 'text_summary_or_trimmed');

    field_update_instance($instance);
  }

  // Basic Pages can have a main-menu item.
  variable_set('menu_options_page', array('main-menu'));

  // Links shouldn't be on a menu.
  variable_set('menu_options_link', array());

  // Allow visitor account creation with administrative approval.
  variable_set('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL);

  // Enable the default and admin theme.
  $enable = array(
    'theme_default' => 'cambridge_theme',
    'admin_theme' => 'seven',
  );
  theme_enable($enable);

  foreach ($enable as $var => $theme) {
    if (!is_numeric($var)) {
      variable_set($var, $theme);
    }
  }

  theme_disable(array('bartik'));

  // Use the admin theme for creating/editing nodes
  variable_set('node_admin_theme', 1);

  // Insert the horizontal menu block required by the theme
  variable_set("menu_block_1_title_link", 0);
  variable_set("menu_block_1_admin_title", 'Horizontal menu');
  variable_set("menu_block_1_parent", 'main-menu:0');
  variable_set("menu_block_1_level", '1');
  variable_set("menu_block_1_follow", 0);
  variable_set("menu_block_1_depth", '0');
  variable_set("menu_block_1_expanded", 1);
  variable_set("menu_block_1_sort", 0);

  // Insert the vertical menu block required by the theme
  variable_set("menu_block_2_title_link", 0);
  variable_set("menu_block_2_admin_title", 'Vertical menu');
  variable_set("menu_block_2_parent", 'main-menu:0');
  variable_set("menu_block_2_level", '1');
  variable_set("menu_block_2_follow", 'active');
  variable_set("menu_block_2_depth", '0');
  variable_set("menu_block_2_expanded", 0);
  variable_set("menu_block_2_sort", 1);

  variable_set('menu_block_ids', array(1, 2));

  // Hide Drupal's standard menu blocks
  variable_set('menu_block_suppress_core', 1);

  $theme = 'cambridge_theme';

  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'title' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'user',
      'delta' => 'login',
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 10,
      'region' => 'sidebar',
      'pages' => '',
      'title' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'menu_block',
      'delta' => 1,
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'horizontal_navigation',
      'pages' => '',
      'title' => '<none>',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'menu_block',
      'delta' => 2,
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'left_navigation',
      'pages' => "<front>\nadmin/\nadmin/*\ncarousel/*\nuser\nuser/*search\nsearch/*",
      'title' => '<none>',
      'cache' => DRUPAL_NO_CACHE,
    ),
  );

  $query = db_insert('block')
    ->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'title', 'cache'));

  foreach ($blocks as $block) {
    $query->values($block);
  }

  $query->execute();

  // Insert default pre-defined RDF mapping into the database.
  $rdf_mappings = array(
    array(
      'type' => 'node',
      'bundle' => 'page',
      'mapping' => array(
        'rdftype' => array('foaf:Document'),
      ),
    ),
  );
  foreach ($rdf_mappings as $rdf_mapping) {
    rdf_mapping_save($rdf_mapping);
  }

  // Enable default permissions for system roles.
  $filtered_html_permission = filter_permission_name($filtered_html_format);
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access content', $filtered_html_permission));
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access content', $filtered_html_permission));

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();

  // Reset anonymous and authenticated user permissions.

  user_role_grant_permissions(1, array('access content', 'search content'));
  user_role_grant_permissions(2, array('access content', 'search content'));

  // Create a Home link in the main menu.
  $item = array(
    'link_title' => st('Home'),
    'link_path' => '<front>',
    'menu_name' => 'main-menu',
    'weight' => -100,
  );
  menu_link_save($item);

  // Update the menu router information.
  menu_rebuild();

  // Create an example carousel view of recent content and make it visible on the front page.

  $view = new view();
  $view->name = 'carousel';
  $view->description = 'Used to promote key messages on section pages.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  $handler = $view->new_display('default', 'Recent Content', 'default');
  $handler->display->display_options['title'] = 'Carousel';
  $handler->display->display_options['css_class'] = 'section-carousel campl-carousel clearfix campl-banner';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'campl-slide campl-column12';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'campl-unstyled-list campl-slides';
  $handler->display->display_options['style_options']['wrapper_class'] = 'campl-carousel-container';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'carousel_item';
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';

  $handler = $view->new_display('block', 'Homepage', 'block');
  $handler->display->display_options['block_description'] = 'Homepage Carousel';

  $view->update();

  $view->init_display();

  $view->save();

  db_insert('block')
    ->fields(
      array(
        'module' => 'views',
        'delta' => 'carousel-block',
        'theme' => 'cambridge_theme',
        'status' => TRUE,
        'weight' => 0,
        'region' => 'carousel',
        'custom' => BLOCK_CUSTOM_FIXED,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => '<front>',
        'title' => '<none>',
        'cache' => DRUPAL_NO_CACHE,
      )
    )
    ->execute();

  // Make the related links view block visible in the sidebar.

  db_insert('block')
    ->fields(
      array(
        'module' => 'views',
        'delta' => 'related_links-block',
        'theme' => 'cambridge_theme',
        'status' => TRUE,
        'weight' => -10,
        'region' => 'sidebar',
        'custom' => BLOCK_CUSTOM_FIXED,
        'visibility' => BLOCK_VISIBILITY_NOTLISTED,
        'pages' => '',
        'title' => '',
        'cache' => DRUPAL_NO_CACHE,
      )
    )
    ->execute();

  // Set some sensible defaults for the Image javascript crop module.

  variable_set('imagecrop_popup', 'basic');
  variable_set('imagecrop_scale_default', 1);
  variable_set('imagecrop_ui_controls', 1);
}

/**
 * Allows the profile to alter the site configuration form.
 */
function cambridge_base_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the default country with United Kingdom.
  $form['server_settings']['site_default_country']['#default_value'] = 'GB';

  // Make sure the timezone is Europe/London.
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/London';
  unset($form['server_settings']['date_default_timezone']['#attributes']['class']);

  // Only check for updates, no need for email notifications.
  $form['update_notifications']['update_status_module']['#default_value'] = array(1);
}
