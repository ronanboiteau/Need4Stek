/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Thu May  5 01:35:56 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_lidar.h"

int		main(void)
{
  float		*info;

  my_printf("%s", "START_SIMULATION\n");
  while (42)
    {
      if (!(info = get_info_lidar()))
      	return (EXIT_FAILURE);
      my_printf("%s", "CAR_FORWARD:0.5\n");
    }
  my_printf("%s", "STOP_SIMULATION\n");
  return (EXIT_SUCCESS);
}
