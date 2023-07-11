# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 21:48:33 by minjinki          #+#    #+#              #
#    Updated: 2023/07/11 15:25:47 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ClapTrap

SRC_FILES	=	main\
				ClapTrap

SRCS		=	$(addsuffix .cpp, $(SRC_FILES))

OBJS		=	$(SRCS:%.cpp=%.o)

CXX			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

all			:	$(NAME)

%.o			:	%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re