/*
** my_printenv.c for my_printenv in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan  3 18:37:33 2016 Ronan Boiteau
** Last update Tue Apr 12 23:20:04 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

void		my_printenv(char **env, char separator)
{
  t_uint	idx;

  idx = 0;
  while (env != NULL && env[idx])
    {
      my_printf("%s%c", env[idx], separator);
      idx += 1;
    }
  return ;
}
