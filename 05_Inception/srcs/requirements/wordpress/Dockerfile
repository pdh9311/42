FROM debian:buster

COPY ./tools/setup.sh /tmp

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y \
	vim wget curl \
	php7.3-fpm php-mbstring php-mysql \
	sendmail \
	mariadb-client \
	dumb-init \
	procps \
	&& curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp \
	&& chmod +x /usr/local/bin/wp \
	&& chmod +x /tmp/setup.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["/tmp/setup.sh"]