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

  $form[] = array(
    '#markup' => t('Some themes will cover up the default contextual links with the admin bar. Check either of the below to shift the layout contextual links downward for the specified theme.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  $themes = list_themes();
  $theme_default = $themes[config_get('system.core', 'theme_default')];
  $recommendation = _layout_contextual_links_recommendation($theme_default);
  $form['default_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift for default theme'),
    '#description' => t('Shift contextual links downward for all pages that display the admin bar in the default theme (!recommendation).', array('!recommendation' => $recommendation)),
    '#default_value' => $config->get('default_theme_shift'),
  );
  $admin_theme = $themes[config_get('system.core', 'admin_theme')];
  $recommendation = _layout_contextual_links_recommendation($admin_theme);
  $form['admin_theme_shift'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shift for admin theme'),
    '#description' => t('Shift contextual links downward for all pages that display the admin bar in the admin theme (!recommendation).', array('!recommendation' => $recommendation)),
    '#default_value' => $config->get('admin_theme_shift'),
  );

  return system_settings_form($form);
}

/**
 * Return recommendation message for the specified theme.
 */
function _layout_contextual_links_recommendation($theme) {
  $needs_shift_themes = array(
    'basis',
    'lateral',
    'mero',
    'shasetsu',
    'tatsu',
  );
  $no_shift_themes = array(
    'afterlite_tribute',
    'bartik',
    'bootstrap_lite',
    'bootstrap5_lite',
    'borg',
    'cleanish',
    'colihaut',
    'corporate_kiss',
    'lumi',
    'materialize',
    'pelerine',
    'seven',
    'snazzy',
  );
  $theme_name = $theme->info['name'];
  if (_layout_contextual_links_theme_based($theme, $needs_shift_themes)) {
    return t('%theme_name, recommended checked', array('%theme_name' => $theme_name));
  }
  elseif (_layout_contextual_links_theme_based($theme, $no_shift_themes)) {
    return t('%theme_name, recommended not checked', array('%theme_name' => $theme_name));
  }
  else {
    return t('theme %theme_name not recognized; try both settings to see which works best', array('%theme_name' => $theme_name));
  }
}

/**
 * Returns whether a theme is based on one of the themes in a list.
 */
function _layout_contextual_links_theme_based($theme, $theme_list) {
  if (in_array($theme->name, $theme_list)) {
    return TRUE;
  }
  if (isset($theme->base_themes)) {
    foreach ($theme->base_themes as $machine_name => $human_name) {
      if (in_array($machine_name, $theme_list)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}
