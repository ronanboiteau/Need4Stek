/*
** match.c for match in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct  4 00:18:09 2015 Ronan Boiteau
** Last update Sun May 29 23:03:09 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

int		match(char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (FALSE);
  if (nmatch(str1, str2) > 0)
    return (TRUE);
  return (FALSE);
}
