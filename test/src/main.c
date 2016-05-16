/*
** main.c for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:11:08 2016 Baptiste veyssiere
** Last update Thu Apr 28 23:56:33 2016 Baptiste veyssiere
*/

#include <stdlib.h>
#include "perfect_maze.h"

int	check_limit_int(char *nbr)
{
  int	i;
  char	length;
  char	*lim;

  i = my_strlen(nbr);
  length = 10;
  lim = "2147483647";
  if (i < length)
    return (0);
  else if (i > length)
    return (1);
  i = -1;
  while (nbr[++i])
    if (nbr[i] > lim[i])
      return (1);
    else if (nbr[i] < lim[i])
      return (0);
  return (0);
}

int	check_if_nbr(char *nbr)
{
  int	i;

  if (nbr == NULL || (nbr[0] < '0' || nbr[0] > '9'))
    return (1);
  i = 0;
  while (nbr[++i])
    if (nbr[i] < '0' || nbr[i] > '9')
      return (1);
  if (check_limit_int(nbr))
    return (1);
  return (0);
}

int		perfect_maze(char *width, char  *height)
{
  t_dimension	*dimension;

  if ((dimension = malloc(sizeof(t_dimension))) == NULL)
    return (my_put_error("Error while using malloc function\n", -1));
  if (check_if_nbr(width))
    return (my_put_error("Invalid width\n", 1));
  if (check_if_nbr(height))
    return (my_put_error("Invalid height\n", 1));
  dimension->width = atoi(width) + 2;
  dimension->height = atoi(height) + 2;
  if (dimension->width < 1)
    return (my_put_error("Invalid negative width\n", 1));
  if (dimension->height < 1)
    return (my_put_error("Invalid negative height\n", 1));
  if (perfect_maze_generator(dimension))
    return (-1);
  free(dimension);
  return (0);
}

int	main(int ac, char **av)
{
  int	error;

  if (ac != 3)
    return (my_put_error("./maze width height\n", -1));
  if ((error = perfect_maze(av[1], av[2])))
    return (error);
  return (0);
}
