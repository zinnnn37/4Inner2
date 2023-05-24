# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 15:07:50 by minjinki          #+#    #+#              #
#    Updated: 2023/05/24 19:56:56 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PhoneBook

SRCS		=	Contact.cpp\
				PhoneBook.cpp\
				main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

all			:	$(NAME)

%.o			:	%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re