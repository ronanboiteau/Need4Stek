/*
** my_strncpy.c for my_strncpy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct  5 09:38:55 2015 Ronan Boiteau
** Last update Mon Jan 18 21:03:15 2016 Ronan Boiteau
*/

#include "my.h"

char		*my_strncpy(char *dest, const char *src, t_uint nbr)
{
  t_uint	idx;

  idx = 0;
  while (idx < nbr && src[idx])
    {
      dest[idx] = src[idx];
      idx += 1;
    }
  dest[idx] = C_NUL;
  return (dest);
}
