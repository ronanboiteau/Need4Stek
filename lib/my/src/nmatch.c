/*
** nmatch.c for nmatch in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Oct 10 22:11:14 2015 Ronan Boiteau
** Last update Mon Jan 18 21:03:58 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

int	nmatch(char *str1, char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (FALSE);
  else if ((*str1 == C_NUL) && (*str2 == C_NUL))
    return (TRUE);
  else if ((*str1 != C_NUL) && (*str2 == '*'))
    return (nmatch(str1, str2 + 1) + nmatch(str1 + 1, str2));
  else if ((*str1 == C_NUL) && (*str2 == '*'))
    return (nmatch(str1, str2 + 1));
  else if ((*str2 != C_NUL) && (*str1 == '*'))
    return (nmatch(str1 + 1, str2) + nmatch(str1, str2 + 1));
  else if ((*str2 == C_NUL) && (*str1 == '*'))
    return (nmatch(str1 + 1, str2));
  else if (*str1 == *str2)
    return (nmatch(str1 + 1, str2 + 1));
  else
    return (FALSE);
}
