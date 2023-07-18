# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:17:00 by minjinki          #+#    #+#              #
#    Updated: 2023/07/18 13:14:52 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	LIBFT/
LIBFT_LIB	=	$(LIBFT)libft.a

SRC_FILES	=	main

MLX			=	../mlx/	# mlx/ 도 해보고 결정
MLX_LIB		=	$(MLX)libmlx.a

SRCS		=	$(addsuffix .c, $(SRC_FILES))
OBJS		=	$(SRCS:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CLIB		=	-Lmlx -lmlx -framework OpenGL -framework Appkit
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	make -C $(MLX) all
	make -C $(LIBFT) all
	$(CC) $(CFLAGS) $(CLIB) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME) -I. -I$(LIBFT) -I$(MLX)

clean		:
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(MLX) fclean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re