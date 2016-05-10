/*
** my_strncat.c for my_strncat in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 20:46:17 2015 Ronan Boiteau
** Last update Tue Jan 19 23:14:27 2016 Ronan Boiteau
*/

#include "my.h"

char		*my_strncat(char *dest, const char *src, int nbr)
{
  int		idx_dest;
  int		idx_src;

  idx_dest = my_strlen(dest);
  idx_src = 0;
  while (idx_src < nbr && src[idx_src])
    {
      dest[idx_dest] = src[idx_src];
      idx_dest += 1;
      idx_src += 1;
    }
  dest[idx_dest] = C_NUL;
  return (dest);
}
