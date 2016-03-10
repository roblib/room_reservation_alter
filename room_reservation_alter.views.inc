<?php

/**
 * @file
 * Views definitions for room_reservation_alter
 */

/**
 * Implementation of hook_views_handlers()
 * Creates a custom field handler that hides the booking name if private.
 */
function room_reservation_alter_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'room_reservation_alter'),
    ),
    'handlers' => array(
      'room_reservation_alter_handler_label' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function room_reservation_alter_views_data() {
  $data = array();
  $data['room_reservation_alter']['table']['group'] = t('Custom');
  $data['room_reservation_alter']['table']['join'] = array(
    '#global' => array(),
  );
  // Add custom field
  $data['room_reservation_alter']['custom_field'] = array(
    'title' => t('Room Reservation Altered Label'),
    'help' => t('Hides the group name if Private.'),
    'field' => array(
      'handler' => 'room_reservation_alter_handler_label',
    ),
  );
  return $data;
}
