NAME		= inception

YML_PATH	= ./srcs/docker-compose.yml
VOLUMES		= /home/minjinki/data

all		:
	mkdir -p ${VOLUMES}/db-data ${VOLUMES}/wp-data
	make build

build	:
	docker-compose -f ${YML_PATH} build
	make up

up		:
	docker-compose -f ${YML_PATH} up -d

down	:
	docker-compose -f ${YML_PATH} down

clean	:
	make down
	docker system prune -a

fclean	:
	make clean
	docker-compose -f ${YML_PATH} down --volumes
	sudo rm -rf ${VOLUMES}

re		:
	make fclean
	make all

.PHONY	: all up down clean fclean re
