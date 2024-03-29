/*
** path_finder.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 19:25:19 2016 Nathan Scutari
** Last update Thu Jun  2 19:20:47 2016 Nathan Scutari
*/

#include <unistd.h>
#include <stdlib.h>
#include "dante.h"

static t_node	*chose_current(t_node **list, char **map, t_node **close)
{
  int		min;
  t_node	*open;
  t_node	*shorter;

  open = *list;
  shorter = open;
  min = open->value;
  while (open != NULL)
    {
      if (open->value < min)
	{
	  min = open->value;
	  shorter = open;
	}
      open = open->next;
    }
  remove_from_list(list, shorter, close);
  map[shorter->pos.y][shorter->pos.x] = 'o';
  return (shorter);
}

static t_node	*in_the_list(t_node *list, int x, int y)
{
  while (list != NULL)
    {
      if (list->pos.x == x && list->pos.y == y)
	return (list);
      list = list->next;
    }
  return (NULL);
}

static void	compare_value(t_node *current, t_node *compare)
{
  int	new_value;

  new_value = compare->dist_to_end + (current->dist_to_start + 1);
  if (new_value < compare->value)
    {
      compare->previous = current;
      compare->value = new_value;
      compare->dist_to_start = current->dist_to_start + 1;
    }
}

static int		way_back(t_node *list, char **map, t_node *close)
{
  int		x;
  int		y;
  t_node	*tmp;

  y = -1;
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	if (map[y][x] == 'o')
	  map[y][x] = '*';
    }
  tmp = list;
  while (list != NULL)
    {
      map[list->pos.y][list->pos.x] = 'o';
      list = list->previous;
    }
  free_list(tmp);
  free_list(close);
  return (0);
}

int	path_finder(t_node *open, char **map, t_pos *pos, t_node *close)
{
  int		i;
  t_pos		n_pos[4];
  t_node	*compare;
  t_node	*current;

  prep_pos(n_pos);
  while (open != NULL)
    {
      print_map(map);
      i = -1;
      current = chose_current(&open, map, &close);
      while (++i < 4)
	if (POSX >= 0 && POSY >= 0 && map[POSY] && map[POSY][POSX] == '*')
	  {
	    pos[0].x = POSX;
	    pos[0].y = POSY;
	    if ((compare = in_the_list(open, POSX, POSY)))
	      compare_value(current, compare);
	    else if (add_to_list(&open, current, pos))
	      return (1);
	    if (POSX == pos[1].x && POSY == pos[1].y)
	      return (way_back(open, map, close));
	  }
    }
  write(1, "No solution found\n", 18);
  return (1);
}
