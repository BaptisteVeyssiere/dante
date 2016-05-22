/*
** dante.h for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:08:24 2016 Nathan Scutari
** Last update Sun May 22 19:02:48 2016 Nathan Scutari
*/

#ifndef DANTE_H_
# define DANTE_H_

# define POSX current->pos.x + n_pos[i].x
# define POSY current->pos.y + n_pos[i].y

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_node
{
  t_pos		pos;
  int		value;
  int		dist_to_start;
  int		dist_to_end;
  struct s_node	*previous;
  struct s_node	*next;
}		t_node;

/*
** tools.c
*/
int	my_strlen(char *);
int	my_wordtablen(char **);
void	prep_pos(t_pos *);
void	remove_from_list(t_node **, t_node *, t_node **);

/*
** list_management.c
*/
int	add_to_list(t_node **, t_node *, t_pos *);
void	free_list(t_node *);

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
int	path_finder(t_node *, char **, t_pos *, t_node *);

#endif /* !DANTE_H */
