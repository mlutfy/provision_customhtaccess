<?php

/**
 * Inject the relevant Apache configuration in the site vhost
 */
function provision_customhtaccess_provision_apache_vhost_config($data = null) {
  $htaccess  = d()->site_path . '/htaccess-custom';

  if (file_exists($htaccess)) {
    drush_log(dt('Custom htaccess: found ' . $htaccess));
    return "Include " . d()->site_path . '/htaccess-custom' . "\n";
  }

  return '';
}

