##
## Makefile for solver in /home/scutar_n/rendu/dante/profondeur
##
## Made by Nathan Scutari
## Login   <scutar_n@epitech.net>
##
## Started on  Mon May 16 18:09:02 2016 Nathan Scutari
## Last update Fri May 27 15:59:45 2016 Baptiste veyssiere
##

NAME	= solver

CC	= gcc

RM	= rm -f

MKDIR	= mkdir -p

RMDIR	= rm -rf

SRC	= src/main.c \
	src/get_next_line.c \
	src/get_map.c \
	src/error.c \
	src/path_finder.c \
	src/tools.c

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
	@echo "Cleanup complete!"

fclean: clean
	@$(RM) $(NAME)
	@echo $(NAME)" erased!"

re: fclean all

.PHONY: all clean fclean re
