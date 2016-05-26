/*
** saver.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:58:41 2016 Baptiste veyssiere
** Last update Thu May 26 18:04:19 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include "perfect_maze.h"

int		saver(t_cell ***maze)
{
  int		i;
  int		j;

  i = 0;
  while (maze[++i + 1] != NULL)
    {
      j = 0;
      while (maze[i][++j + 1] != NULL)
	if (write(1, &(maze[i][j]->wall), 1) == -1)
	  return (-1);
      if (maze[i + 2] != NULL && write(1, "\n", 1) == -1)
	return (-1);
    }
  return (0);
}
