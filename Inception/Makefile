NAME = Inception

COMPOSE_DIR = ./srcs
COMPOSE_FILE = docker-compose.yml
DNS_DIR = ./srcs/requirements/tools

all : $(NAME)

$(NAME) :
	$(DNS_DIR)/setup.sh
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) up -d --build --force-recreate

clean :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) down -v --rmi all

fclean : clean
	sudo rm -rf ${HOME}/data
	docker system prune --volumes --all --force
	docker network prune --force
	docker volume prune --force

re : fclean all

ps :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) ps

start :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) start

stop :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) stop

restart :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) restart

log :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) logs -f

up :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) up -d

down :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) down

top :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) top mariadb
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) top wordpress
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) top nginx

exec_nginx :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) exec -it nginx /bin/bash

exec_wordpress :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) exec -it wordpress /bin/bash

exec_mariadb :
	docker compose -f $(COMPOSE_DIR)/$(COMPOSE_FILE) exec -it mariadb /bin/bash

.PHONY : all, clean, fclean, re, start, stop, restart, log, ps, up, down
