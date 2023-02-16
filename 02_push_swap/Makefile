# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:46:45 by minjinki          #+#    #+#              #
#    Updated: 2023/02/15 11:41:07 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECKER		=	checker

INCLUDE		=	include
INCLUDE_BNS	=	checker_include\

SRC_DIR		=	src/
SRC_FILES	=	push_swap\
				command1\
				command2\
				parse\
				ranking\
				sort_small_numbers\
				sort_utils\
				sort\
				stack\
				utils

BNS_DIR		=	checker_src/
BNS_FILES	=	checker\
				command1_bonus\
				command2_bonus\
				do_op_bonus\
				parse_bonus\
				stack_bonus\
				utils_bonus\

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS_BNS	=	$(addprefix $(BNS_DIR), $(addsuffix .c, $(BNS_FILES)))

OBJS		=	$(SRCS:%.c=%.o)
OBJS_BNS	=	$(SRCS_BNS:%.c=%.o)

LIBFT		=	libft/
LIBFT_LIB	=	$(LIBFT)libft.a

GNL			=	gnl/
GNL_LIB		=	$(GNL)libgnl.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

all			:	$(NAME)

bonus		:	$(NAME) $(CHECKER)

%.o			:	%c
	$(CC) $(CFLAGS) -IHDRS -c $< -o $@

$(NAME)		:	$(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) -I$(INCLUDE) -I$(LIBFT)

$(CHECKER)	:	$(OBJS_BNS)
	$(MAKE) -C $(GNL)
	$(CC) $(CFLAGS) $(OBJS_BNS) $(LIBFT_LIB) $(GNL_LIB) -o $(CHECKER) -I$(INCLUDE_BNS) -I$(LIBFT) -I$(GNL)

clean		:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(GNL) clean
	$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(GNL) fclean
	$(RM) $(NAME) $(CHECKER)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:	all bonus clean fclean re