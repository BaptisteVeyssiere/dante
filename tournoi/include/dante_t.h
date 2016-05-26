/*
** dante.h for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:08:24 2016 Nathan Scutari
** Last update Fri May 27 00:55:17 2016 Baptiste veyssiere
*/

#ifndef DANTE_T_H_
# define DANTE_T_H_

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

/*
** prep_n_free.c
*/
void	free_tree(t_tree *);
void	free_map(char **);
t_layer	*prep_layer(t_tree *, char **);
t_tree	*prep_tree(void);

/*
** end.c
*/
void	free_layer(t_layer *);
int	finish_him(char **, t_tree *, t_layer *);

#endif /* !DANTE_T_H_ */
