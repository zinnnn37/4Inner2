# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:27:27 by MJKim             #+#    #+#              #
#    Updated: 2023/05/17 14:48:27 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:%.c=%.o)

CC		=	clang++
CCFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

all		:	$(NAME)

%.o		:	%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:
	$(MAKE) fclean
	$(MAKE) all

.PHONY	:	all clean fclean re