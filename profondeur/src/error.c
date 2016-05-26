/*
** error.c for solver in /home/scutar_n/rendu/dante/profondeur
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon May 16 18:27:22 2016 Nathan Scutari
** Last update Fri May 27 00:54:11 2016 Baptiste veyssiere
*/

#include <unistd.h>
#include "dante_p.h"

int	perr(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
