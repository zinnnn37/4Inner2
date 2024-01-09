FROM alpine:3.18.5

RUN apk update \
     && apk upgrade \
     && apk add --no-cache nginx openssl dumb-init \
     && mkdir -p /etc/ssl

EXPOSE 443

COPY ./conf/default.conf /etc/nginx/http.d

RUN  openssl req \
     -newkey rsa:4096 \
     -days 365 \
     -nodes \
     -x509 \
     -out /etc/ssl/minjinki.42.fr.crt \
     -keyout /etc/ssl/minjinki.42.fr.key \
     -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Development/CN=minjinki"

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["nginx", "-g", "daemon off;"]
