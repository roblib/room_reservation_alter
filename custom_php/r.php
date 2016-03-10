<?php

define(DRUPAL_ROOT, getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
if(isset($_GET['r']) && $_GET['r'] != '' && strpos($_GET['r'],'https://rooms.library.upei.ca')===0){
  header('location: '.$_GET['r']);
}else{
  header('location: https://rooms.library.upei.ca');
}