/*
** main.c for dante in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:26:00 2016 Nathan Scutari
** Last update Fri May 27 15:06:58 2016 Baptiste veyssiere
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "dante.h"

void	print_map(char **map)
{
  int	x;
  int	y;

  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	write(1, &map[y][x], 1);
      write(1, "\n", 1);
    }
}

void	free_tree_map(t_tree *tree, char **map)
{
  free_tree(tree);
  free_map(map);
}

int	prof_solver(char *file_name)
{
  t_pos	pos;
  char	**map;
  int	fd;
  t_layer	*layer;
  t_tree	*tree;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (perr("Error while trying to open the file\n"));
  if ((map = get_map(fd)) == 0)
    return (perr("The map is incorrect\n"));
  pos.x = my_strlen(map[0]) - 1;
  pos.y = my_wordtablen(map) - 1;
  if ((tree = prep_tree()) == NULL ||
      (layer = prep_layer(tree, map)) == NULL)
    return (1);
  if (path_finder(tree, layer, &pos, map))
    {
      write(1, "No solution found\n", 18);
      free_tree_map(tree ,map);
      return (0);
    }
  print_map(map);
  free_tree_map(tree, map);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (!env)
    return (1);
  if (ac != 2)
    return (perr("Usage ./solver map_file\n"));
  if (prof_solver(av[1]))
    return (1);
  return (0);
}
