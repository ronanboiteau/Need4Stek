/*
** my_strlen.c for my_strlen in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct  5 02:49:33 2015 Ronan Boiteau
** Last update Mon Jan 18 21:02:25 2016 Ronan Boiteau
*/

#include <stdlib.h>

int		my_strlen(const char *str)
{
  int		idx;

  idx = 0;
  while (str != NULL && str[idx])
    idx += 1;
  return (idx);
}
