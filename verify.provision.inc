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

/**
 * Inject the relevant Nginx configuration in the site vhost/server declaration.
 */
function provision_customhtaccess_provision_nginx_vhost_config($uri, $data = null) {
  $htaccess  = d()->site_path . '/nginx-custom.conf';

  if (file_exists($htaccess)) {
    drush_log(dt('Custom nginx config: found ' . $htaccess));

    $file = d()->site_path . '/nginx-custom.conf';

    // Block access to the nginx-custom.conf file
    // It's a form of configuration file that is not meant to be public.
    $htaccess  =
        "location = $file {\n"
      . "  deny all;\n"
      . "}\n";

    return $htaccess . "\n" . "include " . $file . ";\n";
  }

  return '';
}
