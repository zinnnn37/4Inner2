# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:47:48 by minjinki          #+#    #+#              #
#    Updated: 2023/01/31 13:13:44 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
			ft_atoi.c\
			ft_calloc.c\
			ft_memset.c\
			ft_putstr.c\
			ft_split.c\
			ft_strlen.c

HDRS	= ./libft.h

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar
ARFLAGS	= 	rcs

NAME	=	libft.a

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)
bonus		:	$(NAME)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)		:	$(OBJS)
			$(AR) $(ARFLAGS) $@ $^

clean		:
			$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
			$(RM) $(NAME)

re		:
			$(MAKE) fclean
			$(MAKE) all

.PHONY		:	all clean fclean re bonus
