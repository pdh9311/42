FROM debian:buster

COPY ./conf/query.sql /tmp
COPY ./tools/setup.sh /tmp

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y \
	vim \
	mariadb-server \
	dumb-init \
	procps \
	&& chmod +x /tmp/setup.sh
	
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["/tmp/setup.sh"]