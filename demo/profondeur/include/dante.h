/*
** dante.h for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:08:24 2016 Nathan Scutari
** Last update Fri May 27 16:52:31 2016 Baptiste veyssiere
*/

#ifndef DANTE_H_
# define DANTE_H_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

/*
** tools.c
*/
int	my_strlen(char *);
int	my_wordtablen(char **);
char	*free_line(char*);

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
int	path_finder(int, int, t_pos *, char **);

#endif /* !DANTE_H_ */
