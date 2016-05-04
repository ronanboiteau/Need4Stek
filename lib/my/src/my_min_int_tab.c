/*
** my_min_int_tab.c for my_min_int_tab in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Nov  2 23:01:00 2015 Ronan Boiteau
** Last update Sun Jan 17 16:23:01 2016 Ronan Boiteau
*/

#include "my.h"

int		my_min_int_tab(const int *tab, const t_uint size)
{
  t_uint	idx;
  int		lowest;

  idx = 0;
  lowest = tab[idx];
  while (idx < size)
    {
      if (tab[idx] > lowest)
	lowest = tab[idx];
      idx += 1;
    }
  return (lowest);
}
