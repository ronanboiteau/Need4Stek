/*
** get_info_lidar.c for n4s in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu May  5 00:10:12 2016 Ronan Boiteau
** Last update Thu May  5 01:36:36 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

/* static char	*epur_raw_info(char *raw) */
/* { */
/*   char		*clean; */

/*   if (!(clean = malloc(sizeof(char) * (my_strlen(raw) + 1)))) */
/*     return (NULL); */
/*   /\* CLEAN *\/ */
/*   free(raw); */
/*   return (clean); */
/* } */

float		*get_info_lidar(void)
{
  char		*raw;
  float		*info;

  info = NULL;

  my_printf("%s", "GET_INFO_LIDAR\n");
  if (!(raw = get_next_line(STDIN)))
    return (NULL);
  /* GET INFO */
  return (info);
}
