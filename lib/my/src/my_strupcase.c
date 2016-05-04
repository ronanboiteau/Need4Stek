/*
** my_strupcase.c for my_strupcase in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 16:56:12 2015 Ronan Boiteau
** Last update Sun Jan 17 16:55:05 2016 Ronan Boiteau
*/

#include "my.h"

char		*my_strupcase(char *str)
{
  t_uint	idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] >= 'a' && str[idx] <= 'z')
	str[idx] = str[idx] - 32;
      idx += 1;
    }
  return (str);
}
