/*
** my_putfloat.c for my_putfloat in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun May 29 22:24:48 2016 Ronan Boiteau
** Last update Sun May 29 22:39:56 2016 Benjamin Dubus
*/

#include "my.h"

void		my_putfloat(int fd, float nbr)
{
  int		idx;

  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_dprintf(fd, "-");
    }
  my_dprintf(fd, "%d", (int)nbr);
  my_dprintf(fd, ".");
  nbr -= (int)nbr;
  nbr *= 10;
  idx = 1;
  while ((int)nbr == 0 && idx < 6)
    {
      nbr *= 10;
      my_dprintf(fd, "0");
      ++idx;
    }
  my_dprintf(fd, "%d", (int)(nbr * my_power(10, 7 - idx - 1)));
  return ;
}
