/*
** my_strdup.c for my_strdup in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Oct  7 08:50:44 2015 Ronan Boiteau
** Last update Tue May 24 10:28:45 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(const char *src)
{
  int		lenght;
  int		idx;
  char		*new_str;

  if (src == NULL)
    return (NULL);
  idx = 0;
  lenght = my_strlen(src);
  if (!(new_str = malloc(sizeof(char) * (lenght + 1))))
    return (NULL);
  while (src[idx])
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}
