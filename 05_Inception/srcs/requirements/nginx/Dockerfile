FROM debian:buster

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y \
	vim \
	nginx \
	openssl \
	procps \
	&& openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42/CN=donpark.42.fr" \
	-keyout /etc/ssl/private/server.key \
	-out /etc/ssl/certs/server.crt

COPY ./conf/default /etc/nginx/sites-available/

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]