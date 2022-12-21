# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:47:48 by minjinki          #+#    #+#              #
#    Updated: 2022/12/21 14:51:18 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
			ft_calloc.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strcmp.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			get_next_line.c\

HDRS	= ../../include/libft.h

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
			$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
			$(RM) $(NAME)

re		:
			$(MAKE) fclean
			$(MAKE) all

.PHONY		:	all clean fclean re bonus
