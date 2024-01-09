sed -i 's/;chdir = \/var\/www/chdir = \/var\/www\/wordpress/g' \
  /etc/php81/php-fpm.d/www.conf
sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' \
  /etc/php81/php-fpm.d/www.conf

if [ ! -f "/var/www/wordpress/index.php" ]
then
  wp core download

  wp config create \
    --dbname=$MYSQL_DATABASE \
    --dbuser=$MYSQL_USER \
    --dbpass=$MYSQL_PASS \
    --dbhost=$MYSQL_HOST

  wp core install \
    --url=$WP_URL \
    --title=$WP_TITLE \
    --admin_user=$WP_ADMIN_NAME \
    --admin_password=$WP_ADMIN_PASS \
    --admin_email=$WP_ADMIN_MAIL

  wp user create $WP_USER_NAME $WP_USER_MAIL \
    --user_pass=$WP_USER_PASS \
    --role=author
fi

php-fpm81 -F