/*
** list_management.c for astar in /home/scutar_n/rendu/dante/astar/src
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun May 22 18:57:11 2016 Nathan Scutari
** Last update Sun May 22 18:59:27 2016 Nathan Scutari
*/

#include <stdlib.h>
#include "dante.h"

int	add_to_list(t_node **open, t_node *current, t_pos *pos)
{
  t_node	*elem;

  if ((elem = malloc(sizeof(t_node))) == NULL)
    return (1);
  elem->next = *open;
  *open = elem;
  elem->pos.x = pos[0].x;
  elem->pos.y = pos[0].y;
  elem->previous = current;
  elem->dist_to_start = current->dist_to_start + 1;
  elem->dist_to_end = pos[1].x - pos[0].x + pos[1].y - pos[0].y;
  elem->value = elem->dist_to_end + elem->dist_to_start;
  return (0);
}

void	free_list(t_node *list)
{
  t_node *tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
