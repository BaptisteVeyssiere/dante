/*
** free_maze.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test/src
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 20:17:37 2016 Baptiste veyssiere
** Last update Wed Apr 27 20:25:02 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include "perfect_maze.h"

void	free_maze(t_cell ***maze)
{
  int	i;
  int	j;

  i = -1;
  while (maze[++i] != NULL)
    {
      j = -1;
      while (maze[i][++j] != NULL)
	free(maze[i][j]);
      free(maze[i]);
    }
  free(maze);
}
