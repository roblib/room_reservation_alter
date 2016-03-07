<?php

/**
 * @file
 * Views definitions for room_reservation_alter
 */

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function room_reservation_alter_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'room_reservation_alter'),
    ),
    'handlers' => array(
// The name of my handler
      'room_reservation_alter_handler_label' => array(
// The name of the handler we are extending.
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
// Add Example group
  $data['room_reservation_alter']['table']['group'] = t('Custom');
  $data['room_reservation_alter']['table']['join'] = array(
// #global is a special flag which lets a table appear all the time.
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
