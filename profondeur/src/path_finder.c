/*
** path_finder.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 19:25:19 2016 Nathan Scutari
** Last update Sun May 29 17:28:45 2016 Nathan Scutari
*/

#include "dante.h"

static void	prep_pos(t_pos *pos, int x, int y)
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

int	clean_map(char **map)
{
  int	y;
  int	x;

  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[++x])
	if (map[y][x] == 'x')
	  map[y][x] = '*';
    }
  return (0);
}

int		path_finder(int x, int y, t_pos *pos, char **map)
{
  int		i;
  int		ret;
  t_pos		n_pos[4];
  static int	stack = 0;

  map[y][x] = 'o';
  if (++stack >= 85000)
    return (2);
  if (pos->x == x && pos->y == y)
    return (clean_map(map));
  prep_pos(n_pos, x, y);
  i = -1;
  while (++i < 4)
    {
      if (n_pos[i].x >= 0 && n_pos[i].y >= 0 && map[n_pos[i].y] &&
	  map[n_pos[i].y][n_pos[i].x] == '*')
	if ((ret = path_finder(n_pos[i].x, n_pos[i].y, pos, map)) != 1)
	  return (ret);
    }
  map[y][x] = 'x';
  --stack;
  return (1);
}
