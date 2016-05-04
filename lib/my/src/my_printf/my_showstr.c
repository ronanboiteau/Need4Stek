/*
** my_showstr.c for my_showstr in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct 19 00:11:18 2015 Ronan Boiteau
** Last update Tue Apr 12 23:22:28 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "printf_puts.h"

int		my_showstr(int fd, const char *str)
{
  t_uint	idx;

  idx = 0;
  if (str == NULL)
    {
      my_putstr_fd(fd, "(null)");
      return (my_strlen("(null)"));
    }
  while (str[idx] != '\0')
    {
      if (my_char_isprintable(str[idx]))
	my_putchar_fd(fd, str[idx]);
      else
	{
	  my_putchar_fd(fd, '\\');
	  if (str[idx] < 16)
	    my_putchar_fd(fd, '0');
	  my_putnbr_base_fd(fd, str[idx], "0123456789abcdef");
	}
      idx += 1;
    }
  return (0);
}
