# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:17:00 by minjinki          #+#    #+#              #
#    Updated: 2022/12/21 14:12:22 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

HDRS		=	include
LIBFT		=	src/libft

SRC_DIR		=	src/
SRC_FILES	=	check_map1.c\
				check_map2.c\
				exit.c\
				game.c\
				init.c\
				key_hook.c\
				put_imgs.c\
				queue.c\
				so_long.c\

MLX			=	mlx/

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(SRCS:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CLIB		=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	makefile $(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

makefile	:
	make -C $(MLX) all
	make -C $(LIBFT) all

$(NAME)		:	$(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean		:
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) clean
	RM $(OBJS)

fclean		:	clean
	$(MAKE) -C $(MLX) fclean
	$(MAKE) -C $(LIBFT) fclean
	RM $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re