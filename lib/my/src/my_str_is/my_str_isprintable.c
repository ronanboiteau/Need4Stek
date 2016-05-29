/*
** my_str_isprintable.c for my_str_isprintable in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:17:26 2015 Ronan Boiteau
** Last update Sun May 29 23:04:30 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

int		my_str_isprintable(const char *str)
{
  t_uint	idx;

  if (str == NULL)
    return (FALSE);
  idx = 0;
  while (str[idx] != '\0')
    {
      if (!((str[idx] >= 32 && str[idx] <= 126) || str[idx] == '\0'
	    || (str[idx] >= 7 && str[idx] <= 13)))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
