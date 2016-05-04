/*
** my_is_prime.c for my_is_prime in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:25:12 2015 Ronan Boiteau
** Last update Thu Dec 17 23:16:27 2015 Ronan Boiteau
*/

#include "my.h"

int		my_is_prime(const int nbr)
{
  int		idx;

  if (nbr <= 1)
    return (FALSE);
  idx = 2;
  while (idx < nbr)
    {
      if (nbr % idx == 0)
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
