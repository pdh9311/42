#! /bin/bash

# /etc/php/7.3/fpm/pool.d
sed -i "s/listen\s=\s.*/listen=0.0.0.0:9000/g" /etc/php/7.3/fpm/pool.d/www.conf

# php-fpm PID 설정
if [ ! -f "/run/php/php7.3-fpm.pid" ]; then
    mkdir -p /run/php/
    echo "1" > /run/php/php7.3-fpm.pid
fi

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
    # wordpress 설치
    wp core download --locale=ko_KR --allow-root --path=/var/www/wordpress
    
    # wp-config.php 파일 생성과 동시에 설정
    wp config create --dbname=$MARIADB_WP_DB --dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PW --dbhost=$MARIADB_HOST --allow-root --path=/var/www/wordpress

    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_ID --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL  --allow-root --path=/var/www/wordpress

    wp user create $WP_USER_ID $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW --allow-root --path=/var/www/wordpress
    chown -R www-data:www-data /var/www/wordpress/
fi

php-fpm7.3 -F --pid /run/php/php7.3-fpm.pid -y /etc/php/7.3/fpm/php-fpm.conf
