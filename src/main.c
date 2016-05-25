/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Wed May 25 14:12:22 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "n4s_algo.h"
#include "n4s_lidar.h"

static int	get_additionnal_info(void)
{
  char		*input;
  int		separator;
  int		idx;

  input = get_next_line(STDIN);
  separator = 0;
  idx = 0;
  while (input[idx] && separator < 3)
    {
      if (input[idx] == ':')
	++separator;
      ++idx;
    }
  while (input[idx])
    {
      if (!my_strncmp(input + idx, "Track Cleared", my_strlen("Track Cleared")))
	{
	  my_printf("CAR_FORWARD:0.0\n");
	  free(input);
	  free(input = get_next_line(STDIN));
	  my_printf("STOP_SIMULATION\n");
	  free(input = get_next_line(STDIN));
	  return (1);
	}
      ++idx;
    }
  free(input);
  return (0);
}

int		main(void)
{
  float		*info;

  my_printf("START_SIMULATION\n");
  if (get_additionnal_info())
    return (EXIT_SUCCESS);
  my_printf("CAR_FORWARD:0.3\n");
  if (get_additionnal_info())
    return (EXIT_SUCCESS);
  while (42)
    {
      if (!(info = get_info_lidar()))
	{
	  my_dprintf(STDERR, "Cannot get lidar data.\n");
	  return (EXIT_FAILURE);
	}
      my_printf((info[0] > info[31] ? "WHEELS_DIR:0.2\n" : "WHEELS_DIR:-0.2\n"));
      if (get_additionnal_info())
	return (EXIT_SUCCESS);
    }
}
