/*
** tools.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:05:09 2016 Nathan Scutari
** Last update Fri May 27 15:08:12 2016 Baptiste veyssiere
*/

#include "dante.h"

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
