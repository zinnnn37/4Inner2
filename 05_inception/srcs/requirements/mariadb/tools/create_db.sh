sed -i "s/skip-networking/skip-networking=0/g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s/.*bind-address\s*=.*/bind-address=0.0.0.0/g" /etc/my.cnf.d/mariadb-server.cnf

mysql_install_db --user=mysql \
				--basedir=/usr \
				--datadir=/var/lib/mysql \
				--skip-test-db

cat > /tmp/create_db.sql << EOF

USE mysql;

FLUSH PRIVILEGES;

CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASS';

GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';

ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASS';

FLUSH PRIVILEGES;

EOF

/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
/usr/bin/mysqld -u mysql

rm -f /tmp/create_db.sql