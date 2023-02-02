# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:26:25 by minjinki          #+#    #+#              #
#    Updated: 2023/02/02 11:36:37 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	get_next_line.c\
				get_next_line_utils.c

HDRS		=	./get_next_line.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar
ARFLAGS		= 	rcs

NAME		=	libgnl.a

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
