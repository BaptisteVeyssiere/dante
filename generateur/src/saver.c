/*
** saver.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:58:41 2016 Baptiste veyssiere
** Last update Sat May 28 17:59:52 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include "perfect_maze.h"

int		saver(t_cell **maze, t_dimension *dimension)
{
  int		i;
  int		j;

  i = 0;
  while ((++i + 1) < dimension->width)
    {
      j = 0;
      while ((++j + 1) < dimension->height)
      	if (write(1, &(maze[i][j].wall), 1) == -1)
      	  return (-1);
      if (i < dimension->width && write(1, "\n", 1) == -1)
	return (-1);
    }
  return (0);
}
