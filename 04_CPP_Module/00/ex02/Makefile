# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 15:07:50 by minjinki          #+#    #+#              #
#    Updated: 2023/07/06 13:37:14 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Account

SRCS		=	Account.cpp\
				tests.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CXX			=	c++
CXXFLAGS		=	-std=c++98
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