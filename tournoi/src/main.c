/*
** main.c for dante in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:26:00 2016 Nathan Scutari
** Last update Sun May 29 22:28:45 2016 Baptiste veyssiere
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
  int	ret;
  t_pos	pos;
  char	**map;
  int	fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (perr("Error while trying to open the file\n"));
  if ((map = get_map(fd)) == 0)
    return (perr("No solution found\n"));
  pos.x = my_strlen(map[0]) - 1;
  pos.y = my_wordtablen(map) - 1;
  if ((ret = path_finder(0, 0, &pos, map)))
    {
      free_wordtab(map);
      if (ret == 1)
	write(1, "No solution found\n", 18);
      else if (ret == 2)
	write(2, "The program is quitting to prevent stack overflow\n", 50);
      return (0);
    }
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
