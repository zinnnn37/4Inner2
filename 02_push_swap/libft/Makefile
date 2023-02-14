# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:47:48 by minjinki          #+#    #+#              #
#    Updated: 2023/02/14 11:36:15 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
			ft_atoi.c\
			ft_calloc.c\
			ft_memset.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_split.c\
			ft_strchr.c\
			ft_strcmp.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strtrim.c

HDRS	= ./libft.h

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar
ARFLAGS	= 	rcs

NAME	=	libft.a

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
