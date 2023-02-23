# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:05:30 by minjinki          #+#    #+#              #
#    Updated: 2023/02/23 12:02:24 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

NAME		=	minishell

INCLUDE		=	include

RL_LIB		=	-lreadline -L${HOME}/.brew/opt/readline/lib
RL_INC		=	-I${HOME}/.brew/opt/readline/include

SRC_DIR		=	src/
SRC_FILES	=	minishell

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(SRCS:%.c=%.o)

ERROR		=	src/error/
ERROR_LIB	=	$(ERROR)liberr.a

LIBFT		=	src/libft/
LIBFT_LIB	=	$(LIBFT)libft.a

# GNL			=	src/gnl/
# GNL_LIB		=	$(GNL)libgnl.a

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(ERROR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(RL_LIB) $(ERROR_LIB) $(LIBFT_LIB)

%.o			:	%c
	$(CC) $(CFLAGS) -I$(INCLUDE) $(RL_INC) -c $< -o $@

clean		:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(ERROR) clean
	$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(ERROR) fclean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re