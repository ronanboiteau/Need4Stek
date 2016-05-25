/*
** my_strdup.c for my_strdup in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Oct  7 08:50:44 2015 Ronan Boiteau
** Last update Tue May 24 19:34:55 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(const char *src)
{
  int		idx;
  char		*new_str;

  if (!src || !(new_str = malloc(sizeof(char) * (my_strlen(src) + 1))))
    return (NULL);
  idx = 0;
  while (src[idx])
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}
