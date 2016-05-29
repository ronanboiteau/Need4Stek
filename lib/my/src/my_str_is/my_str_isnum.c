/*
** my_str_isnum.c for my_str_isnum in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:01:08 2015 Ronan Boiteau
** Last update Sun May 15 20:17:12 2016 Ronan Boiteau
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

int		my_str_isnum(const char *str)
{
  t_uint	idx;

  if (str == NULL)
    return (false);
  idx = 0;
  while (str[idx])
    {
      if (!(str[idx] >= '0' && str[idx] <= '9')
	  && str[idx] != '-' && str[idx] != '+')
	return (false);
      idx += 1;
    }
  return (true);
}
