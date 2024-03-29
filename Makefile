##
## Makefile for dante in /home/VEYSSI_B/rendu/Initiation_IA/dante
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Fri May 27 00:25:01 2016 Baptiste veyssiere
## Last update Fri May 27 16:04:04 2016 Baptiste veyssiere
##

all:
	make -C astar/
	make -C largeur/
	make -C profondeur/
	make -C tournoi/
	make -C generateur/

clean:
	make clean -C astar/
	make clean -C largeur/
	make clean -C profondeur/
	make clean -C tournoi/
	make clean -C generateur/

fclean:
	make fclean -C astar/
	make fclean -C largeur/
	make fclean -C profondeur/
	make fclean -C tournoi/
	make fclean -C generateur/

re: fclean all

.PHONY: all clean fclean re
