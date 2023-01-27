# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 10:22:47 by minjinki          #+#    #+#              #
#    Updated: 2023/01/27 11:07:40 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

UTILS		=	src/utils.c\
				src/utils2.c

all			:	$(CLIENT) $(SERVER)

$(CLIENT)	:	src/client.c
	$(CC) $(CFLAGS) $< $(UTILS) -o $@

$(SERVER)	:	src/server.c
	$(CC) $(CFLAGS) $< $(UTILS) -o $@

clean		:

fclean		:
	$(RM) $(CLINET) $(SERVER)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re