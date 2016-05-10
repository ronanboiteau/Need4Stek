/*
** match.c for match in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct  4 00:18:09 2015 Ronan Boiteau
** Last update Mon Jan 18 20:59:30 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

int		match(char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (FALSE);
  if (nmatch(str1, str2) > 0)
    return (TRUE);
  return (FALSE);
}
