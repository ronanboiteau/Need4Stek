/*
** my_str_isnum.c for my_str_isnum in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:01:08 2015 Ronan Boiteau
** Last update Fri Jan 29 21:14:49 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

int		my_str_isnum(const char *str)
{
  t_uint	idx;

  if (str == NULL)
    return (FALSE);
  idx = 0;
  while (str[idx])
    {
      if (!(str[idx] >= '0' && str[idx] <= '9')
	  && str[idx] != '-' && str[idx] != '+')
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
