/*
** end.c for solver in /home/scutar_n/rendu/dante/largeur/src
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun May 22 19:09:28 2016 Nathan Scutari
** Last update Fri May 27 15:06:32 2016 Baptiste veyssiere
*/

#include <stdlib.h>
#include "dante.h"

void	free_layer(t_layer *layer)
{
  t_layer	*tmp;

  while (layer != NULL)
    {
      tmp = layer;
      layer = layer->next;
      free(tmp);
    }
}

int	finish_him(char **map, t_tree *tree, t_layer *layer)
{
  int	x;
  int	y;

  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	if (map[y][x] == 'o')
	  map[y][x] = '*';
    }
  while (tree)
    {
      map[tree->pos.y][tree->pos.x] = 'o';
      tree = tree->previous;
    }
  free_layer(layer);
  return (0);
}
