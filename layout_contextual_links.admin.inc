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
  $form['default_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift contextual links downward for default theme'),
    '#description' => t('Check this box to shift contextual links downward for all pages in the default theme that display the admin bar.'),
    '#default_value' => $config->get('default_theme_shift'),
  );
  $form['admin_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift contextual links downward for admin theme'),
    '#description' => t('Check this box to shift contextual links downward for all pages in the admin theme that display the admin bar.'),
    '#default_value' => $config->get('admin_theme_shift'),
  );

  return system_settings_form($form);
}
