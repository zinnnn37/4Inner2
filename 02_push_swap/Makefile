# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:46:45 by minjinki          #+#    #+#              #
#    Updated: 2023/02/02 10:14:45 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECKER		=	checker

INCLUDE		=	include
INCLUDE_BNS	=	checker_include

SRC_DIR		=	src/
SRC_FILES	=	push_swap\
				command1\
				command2\
				parse\
				sort_small_numbers\
				stack\
				utils

BNS_DIR		=	checker_src/
BNS_FILES	=	checker\
				command1_bonus\
				command2_bonus\
				parse_bonus\
				stack_bonus\
				utils_bonus

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS_BNS	=	$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_FILES)))

OBJS		=	$(SRCS:%.c=%.o)
OBJS_BNS	=	$(SRCS_BNS:%.c=%.o)

LIBFT		=	libft/
LIBFT_LIB	=	$(LIBFT)libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

bonus		:	$(CHECKER)
	$(MAKE) all

%.o			:	%c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) -I$(INCLUDE) -I$(LIBFT)

$(CHECKER)	:	$(OBJS_BNS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(CHECKER) -I$(INCLUDE_BNS) -I$(LIBFT)

clean		:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all bonus clean fclean re