# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 15:37:44 by minjinki          #+#    #+#              #
#    Updated: 2022/08/04 16:38:51 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HDRS		=	include/ft_printf.h libft/libft.h
LIBFT		=	libft

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar
ARFLAGS		=	src

SRC_DIR		=	src/
SRC_FILES	=	ft_printf ft_print_hex_ptr ft_print_str_nbr_un
SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJT		=	$(SRCS:.c=.o)


all			:	$(NAME)

%.o			:	$(SRC_DIR)%.c
				$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)		:	$(OBJT)
				$(MAKE) -C $(LIBFT)
				cp libft/libft.a ./$(NAME)
				$(AR) $(ARFLAGS) $@ $^

clean		:
				$(RM) $(OBJT)
				make clean -C $(LIBFT)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)/libft.a

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
