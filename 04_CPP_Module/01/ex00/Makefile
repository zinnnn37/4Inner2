# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:27:27 by MJKim             #+#    #+#              #
#    Updated: 2023/06/30 12:04:49 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombie

SRCS	=	main.cpp\
			Zombie.cpp\
			newZombie.cpp\
			randomChump.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

CC		=	c++ #g++로 컴파일

CCFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
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