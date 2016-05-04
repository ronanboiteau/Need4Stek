/*
** my_square_root.c for my_square_root in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct  4 17:40:19 2015 Ronan Boiteau
** Last update Sun Jan 17 16:50:31 2016 Ronan Boiteau
*/

#include "my.h"

int		my_square_root(const int nbr)
{
  t_ll		tmp;
  int		result;

  result = 0;
  if (nbr >= 0)
    {
      while ((tmp = (t_ll)result * (t_ll)result) != nbr && result <= nbr)
	result += 1;
    }
  else
    return (0);
  if (result == nbr + 1)
    return (0);
  else
    return (result);
}
