<?php

/**
 * @file
 * Installation profile.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function cambridge_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the default country with United Kingdom.
  $form['server_settings']['site_default_country']['#default_value'] = 'GB';

  // Make sure the timezone is Europe/London.
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/London';
  unset($form['server_settings']['date_default_timezone']['#attributes']['class']);

  // Only check for updates, no need for email notifications.
  $form['update_notifications']['update_status_module']['#default_value'] = array(1);
}
