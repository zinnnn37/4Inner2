FROM alpine:3.18.5

RUN apk update \
	&& apk upgrade \
	&& apk add --no-cache mariadb mariadb-client dumb-init \
	&& mkdir -p /run/mysqld /var/lib/mysql \
	&& chown -R mysql:mysql /run/mysqld

EXPOSE 3306

COPY ./tools/create_db.sh /tmp/create_db.sh
RUN chmod +x /tmp/create_db.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "/tmp/create_db.sh"]
