# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:46:45 by minjinki          #+#    #+#              #
#    Updated: 2023/01/31 14:56:40 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

INCLUDE		=	push_swap.h

SRCS_DIR	=	src/
SRC_FILES	=	push_swap\
				command1\
				command2\
				parse\
				sort_small_numbers\
				stack\
				utils

SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(SRCS:%.c=%.o)

LIBFT		=	libft/
LIBFT_LIB	=	$(LIBFT)libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

%.o			:	%c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) -I. -I$(LIBFT)

clean		:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all clean fclean re