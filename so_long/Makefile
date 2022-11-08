# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:17:00 by minjinki          #+#    #+#              #
#    Updated: 2022/11/08 14:32:13 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out
SRCS		= ./main.c
OBJS		= $(SRCS:%.c=%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CLIB		= -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
RM			= rm -f
AR			= ar
ARFLAGS		= src

all			: $(NAME)

$(NAME)		: $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	RM $(OBJS)

fclean		: clean
	RM $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		: all clean fclean re