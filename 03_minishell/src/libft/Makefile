# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:47:48 by minjinki          #+#    #+#              #
#    Updated: 2023/02/23 12:07:30 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
			ft_putchar.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_strlen.c

HDRS	= ./libft.h

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar
ARFLAGS	= 	rcs

NAME	=	libft.a

OBJS		=	$(SRCS:.c=.o)
OBJS_BNS	=	$(SRCS_BNS:.c=.o)

all			:	$(NAME)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)		:	$(OBJS) $(if $(filter bonus,$(MAKECMDGOALS)), $(OBJS_BNS))
			$(AR) $(ARFLAGS) $@ $^

clean		:
			$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
			$(RM) $(NAME)

re		:
			$(MAKE) fclean
			$(MAKE) all

.PHONY		:	all clean fclean re bonus
