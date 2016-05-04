/*
** my_strdup.c for my_strdup in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Oct  7 08:50:44 2015 Ronan Boiteau
** Last update Wed May  4 17:57:42 2016 Ronan Boiteau
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
  if ((new_str = malloc(sizeof(char) * (lenght + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  while (src[idx])
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}
