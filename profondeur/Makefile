##
## Makefile for solver in /home/scutar_n/rendu/dante/profondeur
## 
## Made by Nathan Scutari
## Login   <scutar_n@epitech.net>
## 
## Started on  Mon May 16 18:09:02 2016 Nathan Scutari
## Last update Tue May 17 16:00:35 2016 Nathan Scutari
##

NAME	= solver

SRCS	= src/main.c \
	  src/get_next_line.c \
	  src/get_map.c \
	  src/error.c \
	  src/path_finder.c \
	  src/tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra -Werror -ansi -pedantic -Iinclude/


$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
