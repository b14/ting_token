<?php
/**
 * Implementation of hook_wysiwyg_plugin().
 */
function ting_token_tingTokenInsert_plugin() {
  $plugins['tingTokenInsert'] = array(
    'title' => t('Insert ting object'),
    'icon file' => 'icon.png',
    'icon title' => t('Insert ting objects'),
    'settings' => array(),
  );
  return $plugins;
}
