/*
** my_revstr.c for my_revstr in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct  5 16:28:45 2015 Ronan Boiteau
** Last update Tue Nov 10 16:59:22 2015 Ronan Boiteau
*/

#include "my.h"

char		*my_revstr(char *str)
{
  char		temp;
  int		idx;
  int		lenght;

  idx = 0;
  lenght = my_strlen(str) - 1;
  while (idx <= lenght / 2)
    {
      temp = str[idx];
      str[idx] = str[lenght - idx];
      str[lenght - idx] = temp;
      idx += 1;
    }
  return (str);
}
