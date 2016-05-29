/*
** perfect_maze.h for perfect_maze in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:16:59 2016 Baptiste veyssiere
** Last update Sat May 28 18:24:28 2016 Baptiste veyssiere
*/

#ifndef PERFECT_MAZE_H_
# define PERFECT_MAZE_H_

typedef struct	s_list
{
  int		x;
  int		y;
  struct s_list	*next;
}		t_list;

typedef struct
{
  char		check;
  char		wall;
}		t_cell;

typedef struct
{
  int		width;
  int		height;
}		t_dimension;

/*
** tools.c
*/
int	my_put_error(char*, int);
int	my_strlen(char*);
int	my_strcmp(char*, char*);

/*
** perfect_maze_generator_init.c
*/
int	perfect_maze_generator(t_dimension*, char);

/*
** check_nbr_of_way.c
*/
int	check_nbr_of_way(t_list*, t_cell**, t_dimension*);
int	get_list_size(t_list*);
t_list	*choose_random_cell(t_list*, int);

/*
** perfect_maze_generator.c
*/
int	generator(t_cell**, t_dimension*);

/*
** free_tab.c
*/
void	free_maze(t_cell**);

/*
** saver.c
*/
int	saver(t_cell**, t_dimension*);

#endif /* !PERFECT_MAZE_H_ */
