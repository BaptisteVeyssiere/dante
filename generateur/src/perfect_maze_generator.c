/*
** perfect_maze_generator.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Apr 28 16:55:01 2016 Baptiste veyssiere
** Last update Sat May 28 18:17:36 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "perfect_maze.h"

static void	remove_cell_from_list(t_list **list, t_list *cell)
{
  t_list	*tmp;
  t_list	*removed;
  t_list	*prev;

  tmp = *list;
  prev = NULL;
  while (*list != NULL && ((*list)->x != cell->x || (*list)->y != cell->y))
    {
      prev = *list;
      *list = (*list)->next;
    }
  removed = *list;
  *list = (*list)->next;
  free(removed);
  if (prev != NULL)
    {
      prev->next = *list;
      *list = tmp;
    }
}

static int	add_elem(t_list **list, int x, int y)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (my_put_error("Error while using malloc function\n", -1));
  elem->x = x;
  elem->y = y;
  elem->next = *list;
  *list = elem;
  return (0);
}

static int	add_around_elem(t_list **list, t_cell **maze,
				t_list *cell, t_dimension *dimension)
{
  maze[cell->x][cell->y].wall = '*';
  if (cell->x > 1)
    {
      if (maze[cell->x - 1][cell->y].wall == '?')
	add_elem(list, (cell->x - 1), cell->y);
    }
  if (cell->x < dimension->width - 2)
    {
      if (maze[cell->x + 1][cell->y].wall == '?')
	add_elem(list, (cell->x + 1), cell->y);
    }
  if (cell->y > 1)
    {
      if (maze[cell->x][cell->y - 1].wall == '?')
	add_elem(list, cell->x, (cell->y - 1));
    }

  if (cell->y < dimension->height - 2)
    {
      if (maze[cell->x][cell->y + 1].wall == '?')
	add_elem(list, cell->x, (cell->y + 1));
    }
  return (0);
}

static int	generator_loop(t_cell **maze, t_dimension *dimension, t_list *list)
{
  t_list	*cell;
  int		list_size;

  list_size = 1;
  while (list != NULL)
    {
      cell = choose_random_cell(list, list_size);
      if (check_nbr_of_way(cell, maze, dimension))
	{
	  maze[cell->x][cell->y].check = 1;
	  if (add_around_elem(&list, maze, cell, dimension) == -1)
	    return (-1);
	  list_size = get_list_size(list);
	}
      else
	{
	  maze[cell->x][cell->y].check = 1;
          maze[cell->x][cell->y].wall = 'X';
	}
      remove_cell_from_list(&list, cell);
      --list_size;
    }
  return (0);
}

int		generator(t_cell **maze, t_dimension *dimension)
{
  t_list	*list;
  int		i;
  int		j;

  list = NULL;
  srand(time(NULL));
  maze[1][0].wall = '*';
  maze[1][0].check = 1;
  if (add_elem(&list, 1, 1) == -1)
    return (-1);
  if (generator_loop(maze, dimension, list) == -1)
    return (my_put_error("Error while allocating list\n", -1));
  i = -1;
  while (++i < dimension->width)
    {
      j = -1;
      while (++j < dimension->height)
	if (maze[i][j].wall == '?')
	  maze[i][j].wall = 'X';
    }
  maze[dimension->width - 2][dimension->height - 2].wall = '*';
  if (maze[dimension->width - 2][dimension->height - 3].wall == 'X' &&
      maze[dimension->width - 3][dimension->height - 2].wall == 'X')
    maze[dimension->width - 2][dimension->height - 3].wall = '*';
  return (0);
}
