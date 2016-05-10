/*
** my_strstr.c for my_strstr in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 11:28:02 2015 Ronan Boiteau
** Last update Mon Jan 18 17:31:59 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

char		*my_strstr(char *str, const char *to_find)
{
  if (my_strlen(to_find) > my_strlen(str))
    return (NULL);
  else
    {
      if (*str == *to_find &&
	  my_strncmp(str, to_find, my_strlen(to_find)) == 0)
	return (str);
      else
	return (my_strstr(str + 1, to_find));
    }
}
