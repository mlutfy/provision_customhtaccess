<?php

/**
 * Inject the relevant Apache configuration in the site vhost
 */
function provision_customhtaccess_provision_apache_vhost_config($uri, $data = null) {
  $htaccess  = d()->site_path . '/htaccess-custom';

  if (file_exists($htaccess)) {
    drush_log(dt('Custom htaccess: found ' . $htaccess));

    $file = d()->site_path . '/htaccess-custom';

    // Block access to the htaccess-custom file
    // It's a form of configuration file that is not meant to be public.
    $htaccess  = 
        "<Directory \"$file\">\n"
      . "  Order deny,allow\n"
      . "  Deny from all\n"
      . "</Directory>\n";

    return $htaccess . "\n" . "Include " . $file . "\n";
  }

  return '';
}
