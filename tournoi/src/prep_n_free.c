/*
** prep_n_free.c for solver in /home/scutar_n/rendu/dante/largeur/src
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun May 22 19:06:11 2016 Nathan Scutari
** Last update Sun May 22 19:28:41 2016 Nathan Scutari
*/

#include <stdlib.h>
#include "dante.h"

void	free_tree(t_tree *tree)
{
  int	i;

  i = -1;
  while (tree->next && tree->next[++i])
    free_tree(tree->next[i]);
  if (tree->next)
    free(tree->next);
  free(tree);
}

void	free_map(char **map)
{
  int	x;

  x = -1;
  while (map[++x])
    free(map[x]);
  free(map);
}

t_layer	*prep_layer(t_tree *tree, char **map)
{
  t_layer	*layer;

  if ((layer = malloc(sizeof(t_layer))) == NULL)
    return (NULL);
  if (map[0][0] != '*')
    return (NULL);
  map[0][0] = 'o';
  layer->node = tree;
  layer->next = NULL;
  return (layer);
}

t_tree	*prep_tree(void)
{
  t_tree	*tree;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->pos.x = 0;
  tree->pos.y = 0;
  tree->next = NULL;
  tree->previous = NULL;
  return (tree);
}
