/*
** tools.c for tools in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:18:16 2016 Baptiste veyssiere
** Last update Wed Apr 27 16:27:08 2016 Baptiste veyssiere
*/

#include <unistd.h>

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  while (s[++i]);
  return (i);
}

int	my_put_error(char *msg, int error)
{
  if (write(2, msg, my_strlen(msg)) == -1)
    return (-1);
  return (error);
}
