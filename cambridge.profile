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
}
