<?php

/**
 * Inject the relevant Apache configuration in the site vhost
 */
function provision_customhtaccess_provision_apache_vhost_config($data = null) {
  $htaccess  = d()->site_path . '/htaccess-custom';

  if (file_exists($htaccess)) {
    drush_log(dt('Custom htaccess: found ' . $htaccess));
    return "Include " . d()->site_path . '/htaccess-custom' . "\n" . "RewriteRule ^devpme/fr/international/haiti-mission2011-fr.html$ /fr/blog/mission-haiti-2011 [R=301,L]";
  }

  return '';
}
