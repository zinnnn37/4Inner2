# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:27:27 by MJKim             #+#    #+#              #
#    Updated: 2023/07/06 13:38:36 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Zombie

SRCS		=	main.cpp\
				Zombie.cpp\
				newZombie.cpp\
				randomChump.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
RM			=	rm -f

all			:	$(NAME)

%.o			:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re