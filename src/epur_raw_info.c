/*
** epur_raw_info.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue May 24 10:51:11 2016 Ronan Boiteau
** Last update Tue May 24 15:46:47 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_lidar.h"

static int	remove_extra_info(char *clean)
{
  char		*tmp;
  int		separator;

  tmp = clean;
  separator = 0;
  while (*tmp && separator < NB_LIDAR_VALUES)
    {
      if (*tmp == ':')
	++separator;
      ++tmp;
    }
  if (separator < NB_LIDAR_VALUES)
    return (1);
  *tmp = '\0';
  if (*(tmp - 1) == ':')
    *(tmp - 1) = '\0';
  return (0);
}

char		*epur_raw_info(char *raw)
{
  char		*tmp;
  char		*clean;
  int		separator;

  tmp = raw;
  if (!(clean = malloc(sizeof(char) * (my_strlen(raw) + 1))))
    return (NULL);
  separator = 0;
  while (*tmp && separator < 3)
    {
      if (*tmp == ':')
	++separator;
      else if (separator == 1 && !my_strncmp(tmp, "KO", 2))
	return (NULL);
      ++tmp;
    }
  if (!(clean = my_strdup(tmp)))
    return (NULL);
  free(raw);
  return (!remove_extra_info(clean) ? clean : NULL);
}
