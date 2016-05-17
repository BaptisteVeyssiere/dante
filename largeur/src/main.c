/*
** main.c for dante in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:26:00 2016 Nathan Scutari
** Last update Mon May 16 22:33:53 2016 Nathan Scutari
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "dante.h"

int	prof_solver(char *file_name)
{
  int	x;
  int	y;
  t_pos	pos;
  char	**map;
  int	fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (perr("Error while trying to open the file\n"));
  if ((map = get_map(fd)) == 0)
    return (perr("The map is incorrect\n"));
  pos.x = my_strlen(map[0]) - 1;
  pos.y = my_wordtablen(map) - 1;
  if (path_finder(0, 0, &pos, map))
    return (perr("Can not find a path\n"));
  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	write(1, &map[y][x], 1);
      write(1, "\n", 1);
    }
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
