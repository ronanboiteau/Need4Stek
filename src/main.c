/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Wed May  4 18:46:24 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static char	*get_info_lida(void)
{
  char		*info;

  my_printf("%s", "GET_INFO_LIDAR\n");
  return (!(info = get_next_line(STDIN)) ? NULL : info);
}

int		main(void)
{
  char		*info;

  my_printf("%s", "START_SIMULATION\n");
  while (42)
    {
      if (!(info = get_info_lida()))
	return (EXIT_FAILURE);
      my_printf("%s", "CAR_FORWARD:0.5\n");
    }
  my_printf("%s", "STOP_SIMULATION\n");
  return (EXIT_SUCCESS);
}
