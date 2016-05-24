/*
** get_info_lidar.c for n4s in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu May  5 00:10:12 2016 Ronan Boiteau
** Last update Tue May 24 15:40:08 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_lidar.h"

/*1:OK:No errors so far:750.0:800.0:900.0:975.0:1050.0:*/
/* 1:OK:No errors so far:600.0:625.0:675.0:700.0:800.0:850.0:900.0:975.0:1125.0:1225.0:1375.0:1500.0:2500.0:2500.0:2750.0:2750.0:2750.0:2750.0:2750.0:2750.0:2750.0:1225.0:1125.0:975.0:850.0:800.0:700.0:675.0:600.0:550.0:525.0:487.5:First CP Cleared: [0][11s 408448275ns] */

static int	get_next_size(const char *clean)
{
  int		size;

  size = 0;
  while (clean[size] != ':')
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
