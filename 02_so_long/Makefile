# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:17:00 by minjinki          #+#    #+#              #
#    Updated: 2023/01/30 11:45:12 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

LIBFT		=	libft/
LIBFT_LIB	=	$(LIBFT)libft.a

SRC_FILES	=	check_map1\
				check_map2\
				check_map3\
				exit\
				game\
				init\
				key_hook\
				put_imgs\
				queue\
				so_long\

MLX			=	mlx/
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