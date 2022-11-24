# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:17:00 by minjinki          #+#    #+#              #
#    Updated: 2022/11/24 13:32:50 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

HDRS		=	include
LIBFT		=	libft

SRC_DIR		=	src/
SRC_FILES	=	check_map1.c\
				check_map2.c\
				exit.c\
				free.c\
				init.c\
				queue.c\
				so_long.c\

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(SRCS:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CLIB		=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	RM $(OBJS)

fclean		:	clean
	RM $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re