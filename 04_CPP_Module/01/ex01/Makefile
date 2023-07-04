# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:27:27 by MJKim             #+#    #+#              #
#    Updated: 2023/07/04 14:09:45 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombie

SRCS	=	main.cpp\
			Zombie.cpp\
			zombieHorde.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

CC		=	c++
CCFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

all		:	$(NAME)

%.o		:	%.cpp
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