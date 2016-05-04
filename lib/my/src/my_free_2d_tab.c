/*
** my_free_2d_tab.c for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Dec 16 17:55:52 2015 Ronan Boiteau
** Last update Tue Apr 12 23:18:28 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

void		my_free_2d_tab(char **tab)
{
  t_uint	idx;

  if (tab == NULL)
    return ;
  idx = 0;
  while (tab[idx])
    {
      free(tab[idx]);
      idx += 1;
    }
  free(tab);
  return ;
}
