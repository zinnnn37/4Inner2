NAME		= printf.a
HDRS		= include
LIBFT		= libft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I
RM			= rm -f
AR			= ar src

SRC_DIR		= src/
SRC_FILES	= ft_printf, ft_print_hex_ptr, ft_print_str_nbr_un
SRCS		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJT		=	$(SRCS:.c=.o)

all			: $(NAME)

%.o			:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@

$(NAME)		: $(OBJT)
			$(MAKE) -C $(LIBFT)	# LIBFT로 이동해서 make를 해라
			cp libft/libft.a .	# libft/libft.a를 현재 디렉토리로 가져와라
			mv libft.a $(NAME)	# libft.a를 printf.a로 > 아카이브 파일이므로 덮어쓰면 printf obj가 추가되겟다..
			$(AR) $(ARFLAGS) $@ $^

clean		:
			$(RM) $(OBJT)
			make clean -C $(LIBFT)

fclean		: clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re			:
			$(MAKE) fclean
			$(MAKE) all

.PHONY		: all clean fclean re