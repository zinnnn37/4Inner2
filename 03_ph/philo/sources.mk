SRCDIR = src
OBJDIR = obj

CFLAGS = -Wall -Wextra  -DDISPLAY_MS
OPTFLAGS = -O3 -march=native

CC = gcc

SRCS =	\
		fork.c					\
		main.c					\
		parse.c					\
		philosopher.c			\
		philosopher_actions.c	\
		simulation_control.c	\
		simulation.c			\
		utils.c					\

TARGET = philo

INCLUDES = include
