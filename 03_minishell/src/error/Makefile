# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:26:25 by minjinki          #+#    #+#              #
#    Updated: 2023/02/23 11:58:47 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	error.c

HDRS		=	../../include/error.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar
ARFLAGS		= 	rcs

NAME		=	liberr.a

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)		:	$(OBJS)
			$(AR) $(ARFLAGS) $@ $^

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:
			$(MAKE) fclean
			$(MAKE) all

.PHONY		:	all clean fclean re bonus
