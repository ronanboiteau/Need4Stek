/*
** nmatch.c for nmatch in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Oct 10 22:11:14 2015 Ronan Boiteau
** Last update Tue Apr 12 23:19:13 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

int	nmatch(char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (FALSE);
  else if ((*str1 == '\0') && (*str2 == '\0'))
    return (TRUE);
  else if ((*str1 != '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1) + nmatch(str1 + 1, str2));
  else if ((*str1 == '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1));
  else if ((*str2 != '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2) + nmatch(str1, str2 + 1));
  else if ((*str2 == '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2));
  else if (*str1 == *str2)
    return (nmatch(str1 + 1, str2 + 1));
  else
    return (FALSE);
}
