# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 16:12:12 by minjinki          #+#    #+#              #
#    Updated: 2023/06/26 19:15:17 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fixed

SRC_FILES	=	main\
				Fixed

SRCS		=	$(addsuffix .cpp, $(SRC_FILES))

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