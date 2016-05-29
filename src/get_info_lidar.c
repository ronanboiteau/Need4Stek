/*
** get_info_lidar.c for n4s in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu May  5 00:10:12 2016 Ronan Boiteau
** Last update Sun May 29 22:37:06 2016 Benjamin Dubus
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_lidar.h"

static int	get_next_size(const char *clean)
{
  int		size;

  size = 0;
  while (clean[size] && clean[size] != ':')
    ++size;
  return (size);
}

static float	*lidar_to_floattab(float *info, char *backup, char *clean)
{
  char		*tmp;
  int		idx;
  int		idx_info;

  idx_info = 0;
  while (*clean)
    {
      if (!(tmp = malloc(sizeof(char) * (get_next_size(clean) + 1))))
	return (NULL);
      idx = 0;
      while (*clean && *clean != ':')
	{
	  tmp[idx] = *clean;
	  ++idx;
	  ++clean;
	}
      tmp[idx] = '\0';
      info[idx_info++] = my_atof(tmp);
      free(tmp);
      if (*clean)
	++clean;
    }
  free(backup);
  return (info);
}

float		*get_info_lidar(void)
{
  char		*clean;
  char		*raw;
  float		*info;

  my_printf("%s", "GET_INFO_LIDAR\n");
  return (!(info = malloc(sizeof(float) * NB_LIDAR_VALUES))
	  || !(raw = get_next_line(STDIN)) || !(clean = epur_raw_info(raw))
	  || !(lidar_to_floattab(info, clean, clean)) ? NULL : info);
}
