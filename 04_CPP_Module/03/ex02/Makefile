# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 21:48:33 by minjinki          #+#    #+#              #
#    Updated: 2023/07/11 15:24:26 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	FragTrap

SRC_FILES	=	main\
				ClapTrap\
				ScavTrap\
				FragTrap

SRCS		=	$(addsuffix .cpp, $(SRC_FILES))

OBJS		=	$(SRCS:%.cpp=%.o)

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
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