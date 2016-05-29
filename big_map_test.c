/*
** big_map_test.c for kkk in /home/scutar_n/rendu/dante
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun May 29 13:23:53 2016 Nathan Scutari
** Last update Sun May 29 13:29:59 2016 Nathan Scutari
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main()
{
  int	fd;
  int	y;
  int	i;

  fd = open("la_map", O_CREAT | O_WRONLY,
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  y = -1;
  while (++y < 9999)
    {
      i = -1;
      while (++i < 10000)
	write(fd, "*", 1);
      write(fd, "\n", 1);
    }
  i = -1;
  while (++i < 9999)
    write(fd, "*", 1);
  write(fd, "X", 1);
}
