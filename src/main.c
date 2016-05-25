/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Wed May 25 15:48:09 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_algo.h"
#include "n4s_lidar.h"

int		main(void)
{
  float		*info;

  my_printf("START_SIMULATION\n");
  if (is_end_of_track())
    return (EXIT_SUCCESS);
  my_printf("CAR_FORWARD:0.3\n");
  if (is_end_of_track())
    return (EXIT_SUCCESS);
  while (42)
    {
      if (!(info = get_info_lidar()))
	{
	  my_dprintf(STDERR, "Cannot get lidar data.\n");
	  return (EXIT_FAILURE);
	}
      my_printf((info[0] > info[31] ? "WHEELS_DIR:0.2\n" : "WHEELS_DIR:-0.2\n"));
      if (is_end_of_track())
	return (EXIT_SUCCESS);
    }
}
