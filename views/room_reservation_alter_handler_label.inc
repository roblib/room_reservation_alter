<?php

/**
 * @file
 * Definition of room_reservation_alter_handler_label
 */

/**
 * Provides a custom views field.
 */
class room_reservation_alter_handler_label extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
// do nothing -- to override the parent query.
  }

  function render($data) {
// If the devel module is enabled, you may view all of the
// data provided by fields previously added in your view.
// Insert PHP code here, or display greeting.
    $node = node_load($data->nid);
    dpm($node);

    $private = isset($node->reservation_block_title) ? $node->reservation_block_title['und'][0]['value'] : 0;
    if ($private) {
      $output = t("Booked");
    }
    else {
      $output = $node->title;
    }
    return $output;
  }
}