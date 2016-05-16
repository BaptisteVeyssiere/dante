/*
** saver.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:58:41 2016 Baptiste veyssiere
** Last update Thu Apr 28 23:57:19 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "perfect_maze.h"

int		saver(t_cell ***maze)
{
  char		*file;
  int		fd;
  mode_t	mode;
  int		i;
  int		j;

  file = "perfect_maze.map";
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, mode)) == -1)
    return (my_put_error("Error while using open function\n", -1));
  i = 0;
  while (maze[++i + 1] != NULL)
    {
      j = 0;
      while (maze[i][++j + 1] != NULL)
	if (write(fd, &(maze[i][j]->wall), 1) == -1)
	  return (-1);
      if (maze[i + 1] != NULL && write(fd, "\n", 1) == -1)
	return (-1);
    }
  if (close(fd) == -1)
    return (my_put_error("Error while using close function\n", -1));
  return (0);
}
