/*
** check_nbr_of_way.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Apr 29 13:37:48 2016 Baptiste veyssiere
** Last update Sun May 29 17:29:14 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "perfect_maze.h"

t_list		*choose_random_cell(t_list *list, int list_size)
{
  int           random;
  int           i;

  random = rand() % list_size;
  i = -1;
  while (++i < random)
    list = list->next;
  list_size = list_size;
  return (list);
}

static void	zero_superior(t_list *cell, t_cell **maze,
			      t_dimension *dimension, int *counter)
{
  if (cell->x > 0 && maze[cell->x - 1][cell->y].wall == '*')
    {
      ++(*counter);
      if (cell->y > 0 && maze[cell->x + 1][cell->y - 1].wall == '*')
	++(*counter);
      if (cell->y < (dimension->height - 1) &&
	  maze[cell->x + 1][cell->y + 1].wall == '*')
	++(*counter);
    }
  if (cell->y > 0 && maze[cell->x][cell->y - 1].wall == '*')
    {
      ++(*counter);
      if (cell->x > 0 && maze[cell->x - 1][cell->y + 1].wall == '*')
        ++(*counter);
      if (cell->x < (dimension->width - 1) &&
	  maze[cell->x + 1][cell->y + 1].wall == '*')
        ++(*counter);
    }
}

static void	limit_inferior(t_list *cell, t_cell **maze,
			       t_dimension *dimension, int *counter)
{
  if (cell->y < (dimension->height - 1) &&
      maze[cell->x][cell->y + 1].wall == '*')
    {
      ++(*counter);
      if (cell->x > 0 && maze[cell->x - 1][cell->y - 1].wall == '*')
	++(*counter);
      if (cell->x < (dimension->width - 1) &&
	  maze[cell->x + 1][cell->y - 1].wall == '*')
	++(*counter);
    }
  if (cell->x < (dimension->width - 1) &&
      maze[cell->x + 1][cell->y].wall == '*')
    {
      ++(*counter);
      if (cell->y > 0 && maze[cell->x - 1][cell->y - 1].wall == '*')
	++(*counter);
      if (cell->y < (dimension->height + 1) &&
	  maze[cell->x - 1][cell->y + 1].wall == '*')
	++(*counter);
    }
}

int	check_nbr_of_way(t_list *cell, t_cell **maze, t_dimension *dimension)
{
  int	counter;

  counter = 0;
  zero_superior(cell, maze, dimension, &counter);
  limit_inferior(cell, maze, dimension, &counter);
  if (counter == 1)
    return (1);
  else
    return (0);
}

int	get_list_size(t_list *list)
{
  int	nbr;

  nbr = 0;
  while (list != NULL)
    {
      list = list->next;
      ++nbr;
    }
  return (nbr);
}
