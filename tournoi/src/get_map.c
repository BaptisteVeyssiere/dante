/*
** get_map.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:53:46 2016 Nathan Scutari
** Last update Sun May 22 19:32:15 2016 Nathan Scutari
*/

#include <stdlib.h>
#include <unistd.h>
#include "dante.h"
#include "get_next_line.h"

static char	**realloc_map(char *line, char **map)
{
  int	i;
  char	**new_map;

  i = -1;
  if ((new_map = malloc(sizeof(char *) * (my_wordtablen(map) + 2))) == NULL)
    return (NULL);
  while (map && map[++i])
    new_map[i] = map[i];
  if (!map)
    i = 0;
  new_map[i] = line;
  new_map[++i] = NULL;
  if (map)
    free(map);
  return (new_map);
}

static int	verify_map(char	**map)
{
  int	i;
  int	x;
  int	length;

  i = -1;
  length = my_strlen(map[0]);
  while (map[++i])
    {
      if (my_strlen(map[i]) != length)
	return (1);
      x = -1;
      while (map[i][++x])
	if (map[i][x] != 'X' && map[i][x] != '*')
	  return (1);
    }
  return (0);
}

char	**get_map(int fd)
{
  char	**map;
  char	*line;

  map = NULL;
  while ((line = get_next_line(fd)))
    {
      if ((map = realloc_map(line, map)) == NULL)
	return (NULL);
    }
  if (verify_map(map))
    return (NULL);
  return (map);
}
