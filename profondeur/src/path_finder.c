/*
** path_finder.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 19:25:19 2016 Nathan Scutari
** Last update Tue May 17 16:04:41 2016 Nathan Scutari
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include "dante.h"

void	prep_pos(t_pos *pos, int x, int y)
{
  pos[0].x = x + 1;
  pos[0].y = y;
  pos[1].x = x;
  pos[1].y = y + 1;
  pos[2].y = y - 1;
  pos[2].x = x;
  pos[3].x = x - 1;
  pos[3].y = y;
}

void	print_map(char **map)
{
  int	y;
  int	x;

  y = -1;
  system("clear");
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	write(1, &map[y][x], 1);
      write(1, "\n", 1);
    }
  usleep(20000);
}

int	path_finder(int x, int y, t_pos *pos, char **map)
{
  int	i;
  t_pos	n_pos[4];

  map[y][x] = 'o';
  print_map(map);
  if (pos->x == x && pos->y == y)
    return (0);
  prep_pos(n_pos, x, y);
  i = -1;
  while (++i < 4)
    {
      if (map[n_pos[i].y] && n_pos[i].x >= 0 && n_pos[i].y >= 0 &&
	  map[n_pos[i].y][n_pos[i].x] == '*')
	{
	  if (path_finder(n_pos[i].x, n_pos[i].y, pos, map) == 0)
	    return (0);
	}
    }
  map[y][x] = '*';
  print_map(map);
  return (1);
}
