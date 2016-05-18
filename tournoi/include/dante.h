/*
** dante.h for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:08:24 2016 Nathan Scutari
** Last update Wed May 18 12:22:45 2016 Nathan Scutari
*/

#ifndef DANTE_H_
# define DANTE_H_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_tree
{
  t_pos		pos;
  struct s_tree	*previous;
  struct s_tree	**next;
}		t_tree;

typedef struct		s_layer
{
  t_tree		*node;
  struct s_layer	*next;
}			t_layer;

/*
** tools.c
*/
int	my_strlen(char *);
int	my_wordtablen(char **);

/*
** get_map.c
*/
char	**realloc_map(char *, char **);
char	**get_map(int);
void	print_map(char **);

/*
** error.c
*/
int	perr(char *);

/*
** path_finder.c
*/
int	path_finder(t_tree *, t_layer *, t_pos *, char **);
void	prep_pos(t_pos *, int, int);

#endif /* !DANTE_H */
