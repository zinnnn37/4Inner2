# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 15:30:41 by minjinki          #+#    #+#              #
#    Updated: 2022/09/16 13:01:43 by minjinki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
				ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c

SRCS_BNS	=\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

HDRS		=	../include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I

RM			=	rm -f

AR			=	ar
ARFLAGS		= 	rcs

NAME		=	libft.a

OBJS		=	$(SRCS:.c=.o)
OBJS_BNS	=	$(SRCS_BNS:.c=.o)

all			:	$(NAME)
bonus		:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@

$(NAME)		:	$(OBJS) $(if $(filter bonus,$(MAKECMDGOALS)), $(OBJS_BNS))
				$(AR) $(ARFLAGS) $@ $^

clean		:
				$(RM) $(OBJS) $(OBJS_BNS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re bonus
