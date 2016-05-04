/*
** my_str_islower.c for my_str_islower in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:05:52 2015 Ronan Boiteau
** Last update Tue Apr 12 23:22:53 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

int		my_str_islower(const char *str)
{
  t_uint	idx;

  if (str == NULL)
    return (FALSE);
  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 'a' && str[idx] <= 'z'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
