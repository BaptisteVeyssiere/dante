##
## Makefile for dante in /home/VEYSSI_B/rendu/Initiation_IA/dante
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Fri May 27 00:25:01 2016 Baptiste veyssiere
## Last update Fri May 27 00:51:15 2016 Baptiste veyssiere
##

NAME	= solver

NAME_ASTAR	= astar/solver

NAME_LARGEUR	= largeur/solver

NAME_PROFONDEUR	= profondeur/solver

NAME_TOURNOI	= tournoi/solver

RM	= rm -f

CC	= gcc

SRCS_ASTAR	= astar/src/main.c \
	astar/src/get_next_line.c \
	astar/src/get_map.c \
	astar/src/error.c \
	astar/src/path_finder.c \
	astar/src/list_management.c \
	astar/src/tools.c

OBJS_ASTAR	= $(SRCS_ASTAR:.c=.o)

SRCS_LARGEUR	= largeur/src/main.c \
	largeur/src/get_next_line.c \
	largeur/src/prep_n_free.c \
	largeur/src/get_map.c \
	largeur/src/end.c \
	largeur/src/error.c \
	largeur/src/path_finder.c \
	largeur/src/tools.c

OBJS_LARGEUR	= $(SRCS_LARGEUR:.c=.o)

SRCS_PROFONDEUR	= profondeur/src/main.c \
	profondeur/src/get_next_line.c \
	profondeur/src/get_map.c \
	profondeur/src/error.c \
	profondeur/src/path_finder.c \
	profondeur/src/tools.c

OBJS_PROFONDEUR	= $(SRCS_PROFONDEUR:.c=.o)

SRCS_TOURNOI	= tournoi/src/main.c \
	tournoi/src/get_next_line.c \
	tournoi/src/prep_n_free.c \
	tournoi/src/get_map.c \
	tournoi/src/end.c \
	tournoi/src/error.c \
	tournoi/src/path_finder.c \
	tournoi/src/tools.c

OBJS_TOURNOI	= $(SRCS_TOURNOI:.c=.o)

CFLAGS	= -W -Wall -Wextra -Werror -ansi -pedantic -Iastar/include -Ilargeur/include -Iprofondeur/include -Itournoi/include


$(NAME): $(NAME_ASTAR) $(NAME_LARGEUR) $(NAME_PROFONDEUR) $(NAME_TOURNOI)

$(NAME_ASTAR): $(OBJS_ASTAR)
	$(CC) -o $(NAME_ASTAR) $(OBJS_ASTAR)

$(NAME_LARGEUR): $(OBJS_LARGEUR)
	$(CC) -o $(NAME_LARGEUR) $(OBJS_LARGEUR)

$(NAME_PROFONDEUR): $(OBJS_PROFONDEUR)
	$(CC) -o $(NAME_PROFONDEUR) $(OBJS_PROFONDEUR)

$(NAME_TOURNOI): $(OBJS_TOURNOI)
	$(CC) -o $(NAME_TOURNOI) $(OBJS_TOURNOI)

all: $(NAME)

clean:
	$(RM) $(OBJS_ASTAR)
	$(RM) $(OBJS_LARGEUR)
	$(RM) $(OBJS_PROFONDEUR)
	$(RM) $(OBJS_TOURNOI)

fclean: clean
	$(RM) $(NAME_ASTAR)
	$(RM) $(NAME_LARGEUR)
	$(RM) $(NAME_PROFONDEUR)
	$(RM) $(NAME_TOURNOI)

re: fclean all

.PHONY: all clean fclean re
