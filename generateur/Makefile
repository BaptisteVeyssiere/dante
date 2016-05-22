##
## Makefile for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Wed Apr 27 16:13:50 2016 Baptiste veyssiere
## Last update Sun May 22 19:14:35 2016 Baptiste veyssiere
##

NAME	= generateur

SRCS	= src/tools.c \
	src/main.c \
	src/perfect_maze_generator_init.c \
	src/perfect_maze_generator.c \
	src/check_nbr_of_way.c \
	src/free_maze.c	\
	src/saver.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -W -Wall -Wextra -Werror -ansi -pedantic -I./include

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
