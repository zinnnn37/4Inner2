# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 14:44:12 by hroussea          #+#    #+#              #
#    Updated: 2021/08/14 16:42:30 by hroussea         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include sources.mk

SRCS_ = ${addprefix ${SRCDIR}/,${SRCS}}
OBJS_ = ${addprefix ${OBJDIR}/,${SRCS:.c=.o}}
DEPS_ = ${OBJS_:.o=.d}

INCS_ = ${addprefix -I,${INCLUDES}}

NAME = ${TARGET}

OBJDIRS_ = ${shell find ${SRCDIR} -type d | sed s/^${SRCDIR}/${OBJDIR}/g}

all: ${TARGET}

clean:
	rm -rf ${OBJDIR}

fclean: clean
	rm -rf ${TARGET}

re:
	${MAKE} fclean
	${MAKE} all

${TARGET}: ${OBJS_}
	${CC} $^ -o $@

${OBJDIR}:
	mkdir -p ${OBJDIRS_}

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	${CC} ${INCS_} -MMD ${CFLAGS} ${OPTFLAGS} -c $< -o $@

norme:
	norminette ${SRCDIR}

-include ${DEPS_}

.PHONY: all
