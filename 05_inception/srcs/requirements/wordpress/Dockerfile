FROM alpine:3.18.5

RUN apk update \
    && apk upgrade \
    && apk add --no-cache php81 \
        php81-fpm \
        php81-mysqli \
        php81-json \
        php81-curl \
        php81-dom \
        php81-exif \
        php81-fileinfo \
        php81-mbstring \
        php81-openssl \
        php81-xml \
        php81-zip \
        php81-phar \
        php81-iconv \
        mariadb-client \
        curl \
        dumb-init \
    && curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin \
    && chmod +x /usr/local/bin/wp-cli.phar\
    && ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp \
    && mkdir -p /var/www/wordpress

EXPOSE 9000

WORKDIR /var/www/wordpress

COPY ./tools/wordpress.sh /tmp/wordpress.sh
RUN chmod +x /tmp/wordpress.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "/tmp/wordpress.sh"]