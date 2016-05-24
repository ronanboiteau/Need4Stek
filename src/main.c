/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Tue May 24 15:47:17 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_lidar.h"

int		main(void)
{
  float		*info;

  my_printf("%s", "START_SIMULATION\n");
  get_next_line(STDIN);
  my_printf("%s", "CAR_FORWARD:0.4\n");
  get_next_line(STDIN);
  while (42)
    {
      if (!(info = get_info_lidar()))
	{
	  my_dprintf(STDERR, "%s", "Cannot get lidar data.\n");
	  return (EXIT_FAILURE);
	}
      my_printf("%s", "CAR_FORWARD:0.4\n");
      get_next_line(STDIN);
    }
  my_printf("%s", "STOP_SIMULATION\n");
  get_next_line(STDIN);
  return (EXIT_SUCCESS);
}
