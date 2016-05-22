/*
** tools.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:05:09 2016 Nathan Scutari
** Last update Sun May 22 18:59:40 2016 Nathan Scutari
*/

#include <stdlib.h>
#include "dante.h"

void	prep_pos(t_pos *pos)
{
  pos[0].x = 1;
  pos[0].y = 0;
  pos[1].x = 0;
  pos[1].y = 1;
  pos[2].x = 0;
  pos[2].y = -1;
  pos[3].x = -1;
  pos[3].y = 0;
}

void		remove_from_list(t_node **list, t_node *elem, t_node **close)
{
  t_node	*previous;
  t_node	*open;

  previous = NULL;
  open = *list;
  while (open != NULL)
    {
      if (open == elem)
	{
	  if (!previous)
	    *list = open->next;
	  else
	    previous->next = open->next;
	  if ((*close))
	    open->next = *close;
	  else
	    open->next = NULL;
	  *close = open;
	  return ;
	}
      previous = open;
      open = open->next;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i]);
  return (i);
}

int	my_wordtablen(char **wordtab)
{
  int	i;

  i = -1;
  if (!wordtab)
    return (0);
  while (wordtab[++i]);
  return (i);
}
