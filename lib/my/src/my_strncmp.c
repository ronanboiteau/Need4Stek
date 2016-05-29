/*
** my_strncmp.c for my_strncmp.c in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 14:18:14 2015 Ronan Boiteau
** Last update Sun May 29 23:03:16 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

int		my_strncmp(const char *str1, const char *str2, t_uint nbr)
{
  t_uint	idx;

  if (str1 == NULL || str2 == NULL)
    return (-1);
  idx = 0;
  while (str1[idx] != C_NUL && str2[idx] != C_NUL && idx < nbr)
    {
      if (str1[idx] != str2[idx])
	return (str1[idx] - str2[idx]);
      idx += 1;
    }
  if (idx < nbr)
    return (-1);
  return (0);
}
