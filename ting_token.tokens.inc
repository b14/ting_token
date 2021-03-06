<?php

/**
 * @file
 * Main tokens
 */

function ting_token_token_info() {
  $type = array(
    'name' => t('Ding enity'), 
    'description' => t('Display a ding entity.'), 
  );
  
  // Core tokens for nodes.
  $consent['ting'] = array(
    'name' => t("Ding entity"), 
    'description' => t("Show a ding entity."),
  );

  return array(
    'types' => array('ting' => $type), 
    'tokens' => array('ting' => $consent),
  );
}

function ting_token_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }
  $sanitize = !empty($options['sanitize']);
  $replacements = array();
  if ($type == 'ting') {
    foreach ($tokens as $name => $original) {
      $args = explode(':', $name);
      $view_mode = array_shift($args);
      $eid = implode(':', $args);
      if(strpos($eid, ',') !== FALSE) {
        $eids = explode(',', rawurldecode($eid));
      } else {
        $eids = array(rawurldecode($eid));
      }
      
      $entities = ding_entity_load_multiple($eids);
      $output = '<div class="ding-inline-list">';
      foreach($entities as $id => $entity) {
        $object = ding_entity_view($entity, $view_mode);
        if($view_mode == 'list_item') {
          $object['#attributes']['class'][] = format_string('compact');
        }
        $output .= drupal_render($object);
      }
      $output .= '</div>';
      $replacements[$original] = $output;
    }
  }

  return $replacements;
}