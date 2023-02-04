# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 10:22:47 by minjinki          #+#    #+#              #
#    Updated: 2023/02/04 12:01:27 by minjinki         ###   ########.fr        #
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

INCLUDE		=	include
INCLUDE_BNS	=	bonus_include

SRC_DIR		=	src/
SRC_CLIENT	=	client\
				client_hdr\

SRC_SERVER	=	server

SRC_UTILS	=	utils\
				utils2\
				utils3

BNS_DIR		=	bonus_src/
BNS_CLIENT	=	client_bonus\
				client_hdr_bonus\

BNS_UTILS	=	utils_bonus\
				utils2_bonus\
				utils3_bonus

BNS_SERVER	=	server_bonus

SRCS_C		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_CLIENT)))\
				$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS)))

SRCS_S		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS)))\
				$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SERVER)))

SRCS_C_BNS	=	$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_CLIENT)))\
				$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_UTILS)))

SRCS_S_BNS	=	$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_UTILS)))\
				$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_SERVER)))

OBJS_C		=	$(SRCS_C:%.c=%.o)
OBJS_S		=	$(SRCS_S:%.c=%.o)
OBJS_C_BNS	=	$(SRCS_C_BNS:%.c=%.o)
OBJS_S_BNS	=	$(SRCS_S_BNS:%.c=%.o)

all			:	$(CLIENT) $(SERVER)

bonus		:	$(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

%.o			:	%c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT)	:	$(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $@ -I$(INCLUDE)

$(SERVER)	:	$(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $@ -I$(INCLUDE)

$(CLIENT_B)	:	$(OBJS_C_BNS)
	$(CC) $(CFLAGS) $(OBJS_C_BNS) -o $@ -I$(INCLUDE_BNS)

$(SERVER_B)	:	$(OBJS_S_BNS)
	$(CC) $(CFLAGS) $(OBJS_S_BNS) -o $@ -I$(INCLUDE_BNS)

clean		:
	$(RM) $(OBJS_C) $(OBJS_S)
	$(RM) $(OBJS_C_BNS) $(OBJS_S_BNS)

fclean		:
	$(MAKE) clean
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(CLIENT_B) $(SERVER_B)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re