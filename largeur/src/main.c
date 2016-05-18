/*
** main.c for dante in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 17:26:00 2016 Nathan Scutari
** Last update Wed May 18 12:25:52 2016 Nathan Scutari
*/

#define _BSD_SOURCE
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "dante.h"

void	print_map(char **map)
{
  int	x;
  int	y;

  y = -1;
  system("clear");
  while (map[++y])
    {
      x = -1;
      while (map[y][++x])
	write(1, &map[y][x], 1);
      write(1, "\n", 1);
    }
  usleep(100000);
}

t_tree	*prep_tree(void)
{
  t_tree	*tree;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->pos.x = 0;
  tree->pos.y = 0;
  tree->next = NULL;
  tree->previous = NULL;
  return (tree);
}

t_layer	*prep_layer(t_tree *tree, char **map)
{
  t_layer	*layer;

  if ((layer = malloc(sizeof(t_layer))) == NULL)
    return (NULL);
  if (map[0][0] != '*')
    return (NULL);
  map[0][0] = 'k';
  layer->node = tree;
  layer->next = NULL;
  return (layer);
}

void	print_tree(t_tree *tree)
{
  int	i;

  i = -1;
  printf("%d - %d\n", tree->pos.x, tree->pos.y);
  while (tree->next && tree->next[++i])
    print_tree(tree->next[i]);
}

void	free_tree(t_tree *tree)
{
  int	i;

  i = -1;
  while (tree->next && tree->next[++i])
    free_tree(tree->next[i]);
  if (tree->next)
    free(tree->next);
  free(tree);
}

void	free_map(char **map)
{
  int	x;

  x = -1;
  while (map[++x])
    free(map[x]);
  free(map);
}

int	prof_solver(char *file_name)
{
  t_pos	pos;
  char	**map;
  int	fd;
  t_layer	*layer;
  t_tree	*tree;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (perr("Error while trying to open the file\n"));
  if ((map = get_map(fd)) == 0)
    return (perr("The map is incorrect\n"));
  pos.x = my_strlen(map[0]) - 1;
  pos.y = my_wordtablen(map) - 1;
  if ((tree = prep_tree()) == NULL ||
      (layer = prep_layer(tree, map)) == NULL)
    return (1);
  if (path_finder(tree, layer, &pos, map))
    perr("Can not find a path\n");
  print_map(map);
  free_tree(tree);
  free_map(map);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (!env)
    return (1);
  if (ac != 2)
    return (perr("Usage ./solver map_file\n"));
  if (prof_solver(av[1]))
    return (1);
  return (0);
}
