# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 21:48:33 by minjinki          #+#    #+#              #
#    Updated: 2023/07/13 18:43:20 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Materia

SRC_FILES	=	main\
				AMateria\
				Character\
				Cure\
				Ice\
				MateriaSource\
				main

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