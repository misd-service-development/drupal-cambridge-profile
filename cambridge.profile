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
  require_once 'cambridge_base.inc';

  cambridge_base_install_configure_form_alter($form, $form_state);
}
