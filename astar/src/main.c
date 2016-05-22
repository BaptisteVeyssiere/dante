/*
** main.c for dante in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:26:00 2016 Nathan Scutari
** Last update Sun May 22 17:51:58 2016 Baptiste veyssiere
*/


#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "dante.h"

t_node	*prep_node(int x, int y)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos.x = 0;
  node->pos.y = 0;
  node->dist_to_start = 0;
  node->dist_to_end = x + y;
  node->value = x + y;
  node->previous = NULL;
  node->next = NULL;
  return (node);
}

void	print_map(char **map)
{
  int	y;
  int	x;

  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	write(1, &map[y][x], 1);
      write(1, "\n", 1);
    }
}

void	free_wordtab(char **map)
{
  int	y;

  y = -1;
  while (map[++y])
    free(map[y]);
  free(map);
}

int	prof_solver(char *file_name)
{
  t_pos		pos;
  t_pos		posend[2];
  t_node	*node;
  char		**map;
  int		fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (perr("Error while trying to open the file\n"));
  if ((map = get_map(fd)) == 0)
    return (perr("No solution found\n"));
  pos.x = my_strlen(map[0]) - 1;
  pos.y = my_wordtablen(map) - 1;
  posend[1].x = pos.x;
  posend[1].y = pos.y;
  if ((node = prep_node(pos.x, pos.y)) == NULL)
    return (1);
  if (path_finder(node, map, posend, NULL))
    return (1);
  print_map(map);
  free_wordtab(map);
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
