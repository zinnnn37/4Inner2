# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 13:46:30 by minjinki          #+#    #+#              #
#    Updated: 2023/03/30 13:47:17 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

INCLUDE		=	philo.h

SRC_FILES	=	main\
				init\
				run\
				life_cycle\
				monitoring\
				utils

SRCS		=	$(addsuffix .c, $(SRC_FILES))

OBJS		=	$(SRCS:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

%.o			:	%c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDE)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re