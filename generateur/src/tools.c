/*
** tools.c for tools in /home/VEYSSI_B/rendu/Initiation_IA/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Apr 27 16:18:16 2016 Baptiste veyssiere
** Last update Sat May 28 18:01:23 2016 Baptiste veyssiere
*/

#include <unistd.h>

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  if (!s)
    return (0);
  while (s[++i]);
  return (i);
}

int	my_put_error(char *msg, int error)
{
  if (write(2, msg, my_strlen(msg)) == -1)
    return (-1);
  return (error);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = -1;
  while (s1[++i] && s2[i])
    if (s1[i] != s2[i])
      return (0);
  if (s1[i] || s2[i])
    return (0);
  return (1);
}
