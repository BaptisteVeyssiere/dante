/*
** path_finder.c for solver in /home/scutar_n/rendu/dante/largeur/src
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Tue May 17 16:34:42 2016 Nathan Scutari
** Last update Wed May 18 17:48:25 2016 Nathan Scutari
*/

#include <unistd.h>
#include <stdio.h>
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

int	add_in_tree(t_tree *old, t_tree *tree)
{
  int		length;
  t_tree	**next;

  if (!old->next)
    {
      if ((next = malloc(sizeof(t_tree*) * 2)) == NULL)
	return (1);
      next[0] = tree;
      next[1] = NULL;
    }
  else
    {
      length = -1;
      while (old->next[++length]);
      if ((next = malloc(sizeof(t_tree*) * (length + 2))) == NULL)
	return (1);
      length = -1;
      while (old->next[++length])
	next[length] = old->next[length];
      free(old->next);
      next[length] = tree;
      next[++length] = NULL;
    }
  tree->previous = old;
  old->next = next;
  return (0);
}

int	add_in_layer(t_pos pos, t_layer **new_layer, t_layer *old)
{
  t_tree	*tree;
  t_layer	*layer;
  t_layer	*tmp;

  if ((tree = malloc(sizeof(t_tree))) == NULL ||
      (layer = malloc(sizeof(t_layer))) == NULL)
    return (1);
  if (!(*new_layer))
      (*new_layer) = layer;
  else
    {
      tmp = *new_layer;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = layer;
    }
  if (add_in_tree(old->node, tree))
    return (1);
  layer->node = tree;
  tree->pos = pos;
  layer->next = NULL;
  tree->next = NULL;
  return (0);
}

int	explore_node(t_layer *layer, t_layer **new_layer, char **map)
{
  int	i;
  t_pos	exp[4];

  prep_pos(exp, layer->node->pos.x, layer->node->pos.y);
  i = -1;
  while (++i < 4)
    {
      if (exp[i].x >= 0 && exp[i].y >= 0 && map[exp[i].y]
	  && map[exp[i].y][exp[i].x] == '*')
	{
	  map[exp[i].y][exp[i].x] = 'o';
	  if (add_in_layer(exp[i], new_layer, layer))
	    return (1);
	}
    }
  return (0);
}

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

int	path_finder(t_tree *tree, t_layer *layer,
		    t_pos *end, char **map)
{
  t_layer	*save;
  t_layer	*n_layer;

  n_layer = NULL;
  save = layer;
  while (layer != NULL)
    {
      if (layer->node->pos.x == end->x && layer->node->pos.y == end->y)
	return (finish_him(map, layer->node, save));
      if (explore_node(layer, &n_layer, map))
	  return (1);
      layer = layer->next;
    }
  if (n_layer == NULL)
    return (2);
  free_layer(save);
  if  (path_finder(tree, n_layer, end, map))
    return (1);
  return (0);
}
