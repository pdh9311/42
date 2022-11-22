#!/bin/bash

service mysql start
# wordpress 디렉토리가 존재하지 않으면 아직 DB를 생성하지 않았다는 의미이고, DB 설정이 되지않았기 때문에 DB설정을 하겠다는 의미
if [ ! -d "/var/lib/mysql/wordpress" ]; then
    sed -i "s/bind-address\s*=.*/bind-address=0.0.0.0/g" /etc/mysql/mariadb.conf.d/50-server.cnf
    eval "echo \"$(cat /tmp/query.sql)\"" | mysql
fi
mysqladmin -u$MARIADB_ROOT -p$MARIADB_ROOT_PW shutdown
mysqld