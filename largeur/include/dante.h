/*
** dante.h for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:08:24 2016 Nathan Scutari
** Last update Tue May 17 16:02:02 2016 Nathan Scutari
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

/*
** get_map.c
*/
char	**realloc_map(char *, char **);
char	**get_map(int);

/*
** error.c
*/
int	perr(char *);

/*
** path_finder.c
*/
int	path_finder(int, int, t_pos *, char **);
void	prep_pos(t_pos *, int, int);

#endif /* !DANTE_H */
