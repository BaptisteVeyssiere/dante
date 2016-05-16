/*
** perfect_maze_generator_init.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Apr 28 16:52:33 2016 Baptiste veyssiere
** Last update Sun May  1 18:02:33 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "perfect_maze.h"

void	init_maze(t_cell ***maze, t_dimension *dimension)
{
  int	i;
  int	j;

  i = -1;
  while (maze[++i] != NULL)
    {
      j = -1;
      while (maze[i][++j] != NULL)
	{
	  if (i == 0 || j == 0 ||
	      i == (dimension->width - 1) || j == (dimension->height - 1))
	    {
	      maze[i][j]->wall = 'X';
              maze[i][j]->check = 0;
	    }
	  else
	    {
	      maze[i][j]->wall = '?';
	      maze[i][j]->check = 0;
	    }
	}
    }
}

t_cell		***alloc_maze(t_dimension *dimension)
{
  t_cell	***maze;
  int		i;
  int		j;

  if ((maze = malloc(sizeof(t_cell**) * (dimension->width + 1))) == NULL)
    return (NULL);
  maze[dimension->width] = NULL;
  i = -1;
  while (++i < dimension->width)
    {
      if ((maze[i] = malloc(sizeof(t_cell*) * (dimension->height + 1))) == NULL)
        return (NULL);
      maze[i][dimension->height] = NULL;
      j = -1;
      while (++j < dimension->height)
        {
          if ((maze[i][j] = malloc(sizeof(t_cell))) == NULL)
            return (NULL);
        }
    }
  return (maze);
}

void	check_the_path(t_cell ***maze)
{
  if (maze[1][1]->wall == '*' && maze[1][2]->wall == '*' &&
      maze[2][1]->wall == '*' && maze[2][2]->wall == '*')
    maze[1][2]->wall = 'X';
}

int		perfect_maze_generator(t_dimension *dimension)
{
  t_cell	***maze;

  if ((maze = alloc_maze(dimension)) == NULL)
    return (my_put_error("Error while using malloc function\n", -1));
  init_maze(maze, dimension);
  if (generator(maze, dimension) == -1)
    return (-1);
  if (dimension->width == 4 && dimension->height == 4)
    check_the_path(maze);
  if (saver(maze))
    return (-1);
  free_maze(maze);
  return (0);
}
