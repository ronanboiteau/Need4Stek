/*
** my_putstr.c for my_putstr in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 09:33:22 2015 Ronan Boiteau
** Last update Mon Jan 18 17:30:31 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

t_uint		my_putstr_fd(int fd, const char *str)
{
  if (str == NULL)
    {
      write(fd, "(null)", my_strlen("(null)"));
      return (my_strlen("(null)"));
    }
  write(fd, str, my_strlen(str));
  return (my_strlen(str));
}

t_uint		my_putstr(const char *str)
{
  return (my_putstr_fd(STDOUT, str));
}
