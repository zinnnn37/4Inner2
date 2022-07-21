

CC		= cc;
CFLAGS	= -Wall -Wextra -Werror

RM 		= rm -f

AR		= ar
ARFLAGS	= rcs

NAME	= get_next_line.a

OBJT	= $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
		$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)	: $(OBJT)
		$(AR) $(ARFLAGS) $@ $^

clean	:
		$(RM) $(OBJT)

fclean	:	clean
		$(RM) $(NAME)

re		:
		$(MAKE) fclean
		$(MAKE) all

.PHONY	:	all clean fclean re