# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 10:22:47 by minjinki          #+#    #+#              #
#    Updated: 2023/01/30 10:18:21 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server
CLIENT_B	=	client_bonus
SERVER_B	=	server_bonus

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

INCLUDE		=	include/minitalk.h

SRC_UTILS	=	src/utils.c\
				src/utils2.c\
				src/utils3.c

SRC_CLIENT	=	src/client.c\
				src/client_hdr.c

SRC_SERVER	=	src/server.c

ifdef BONUS
	INCLUDE		=	bonus_include/minitalk_bonus.h
	SRC_UTILS	=	bonus_src/utils_bonus.c\
					bonus_src/utils2_bonus.c\
					bonus_src/utils3_bonus.c
	SRC_CLIENT	=	bonus_src/client_bonus.c\
					bonus_src/client_hdr_bonus.c
	SRC_SERVER	=	bonus_src/server_bonus.c
endif

bonus		:
	$(MAKE) BONUS=1 $(CLIENT_B) $(SERVER_B)

all			:	$(CLIENT) $(SERVER)

$(CLIENT)	:	$(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(SRC_UTILS) -o $@

$(SERVER)	:	$(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(SRC_UTILS) -o $@

clean		:
	@echo clean

fclean		:
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(CLIENT_B) $(SERVER_B)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re