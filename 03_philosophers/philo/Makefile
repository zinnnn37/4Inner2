# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:46:45 by minjinki          #+#    #+#              #
#    Updated: 2023/04/11 15:12:43 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

INCLUDE		=	philo.h

SRC_FILES	=	main\
				forks\
				init\
				philo\
				philo_utils\
				simul\
				lifecircle\
				utils\
				utils2\
				free

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