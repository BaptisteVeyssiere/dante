##
## Makefile for solver in /home/scutar_n/rendu/dante/profondeur
##
## Made by Nathan Scutari
## Login   <scutar_n@epitech.net>
##
## Started on  Mon May 16 18:09:02 2016 Nathan Scutari
## Last update Fri May 27 15:57:47 2016 Baptiste veyssiere
##

NAME	= generateur

CC	= gcc

RM	= rm -f

MKDIR	= mkdir -p

RMDIR	= rm -rf

SRC	= src/tools.c \
	src/main.c \
	src/perfect_maze_generator_init.c \
	src/perfect_maze_generator.c \
	src/check_nbr_of_way.c \
	src/free_maze.c \
	src/saver.c

OBJDIR	= obj

SRCDIR	= src

OBJ	= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CFLAGS	= -W -Wall -Wextra -Werror -ansi -pedantic -Iinclude/

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Linkage complete!"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RMDIR) $(OBJDIR)
	@echo "Cleanup Complete"

fclean: clean
	@$(RM) $(NAME)
	@echo $(NAME)" erased!"

re: fclean all

.PHONY: all clean fclean re
