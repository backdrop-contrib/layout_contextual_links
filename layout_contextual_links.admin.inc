<?php
/**
 * @file
 * Administrative page for Layout Contextual Links.
 *
*/

/**
 * Admin settings form.
 */
function layout_contextual_links_settings_form($form, &$form_state) {
  $config = config('layout_contextual_links.settings');
  $form['#config'] = 'layout_contextual_links.settings';

  $form[]= array(
    '#markup' => t('Some themes (e.g., Basis) will cover up the default contextual links with the admin bar. Check either of the below to shift the layout contextual links downward for the specified theme.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  $theme_default = config_get('system.core', 'theme_default');
  $form['default_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift for default theme'),
    '#description' => t('Shift contextual links downward for all pages that display the admin bar in the default theme (%theme_default).', array('%theme_default' => $theme_default)),
    '#default_value' => $config->get('default_theme_shift'),
  );
  $admin_theme = config_get('system.core', 'admin_theme');
  $form['admin_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift for admin theme'),
    '#description' => t('Shift contextual links downward for all pages that display the admin bar in the admin theme (%admin_theme).', array('%admin_theme' => $admin_theme)),
    '#default_value' => $config->get('admin_theme_shift'),
  );

  return system_settings_form($form);
}
