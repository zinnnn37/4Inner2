# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 10:22:47 by minjinki          #+#    #+#              #
#    Updated: 2023/01/27 16:26:44 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

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
	INCLUDE		=	include_bonus/minitalk_bonus.h
	SRC_UTILS	=	src_bonus/utils_bonus.c\
					src_bonus/utils2_bonus.c\
					src_bonus/utils3_bonus.c
	SRC_CLIENT	=	src_bonus/client_bonus.c\
					src_bonus/client_hdr_bonus.c
	SRC_SERVER	=	src_bonus/server_bonus.c
endif

bonus		:
	$(make) BONUS=1 all

all			:	$(CLIENT) $(SERVER)

$(CLIENT)	:	$(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(SRC_UTILS) -o $@

$(SERVER)	:	$(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(SRC_UTILS) -o $@

clean		:
	@echo clean

fclean		:
	$(RM) $(CLIENT) $(SERVER)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re