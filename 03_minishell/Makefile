# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:05:30 by minjinki          #+#    #+#              #
#    Updated: 2023/02/20 11:27:32 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

INCLUDE		=	include

SRC_DIR		=	src/
SRC_FILES	=	minishell

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJS		=	$(SRCS:%.c=%.o)

RL			=	readline
RL_LIB		=	/Users/minjinki/.brew/Cellar/readline/8.2.1/lib
RL_INC		=	/Users/minjinki/.brew/Cellar/readline/8.2.1/include

# LIBFT		=	src/libft/
# LIBFT_LIB	=	$(LIBFT)libft.a

# GNL			=	src/gnl/
# GNL_LIB		=	$(GNL)libgnl.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

%.o			:	%c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDE) -l$(RL) -L$(RL_LIB) -I$(RL_INC)

clean		:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re