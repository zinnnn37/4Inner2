# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 15:26:37 by minjinki          #+#    #+#              #
#    Updated: 2023/02/27 10:32:46 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	remove_sig_output.c

HDRS		=	../../include/utils.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar
ARFLAGS		= 	rcs

NAME		=	libutils.a

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