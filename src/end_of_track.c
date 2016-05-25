/*
** end_of_track.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May 25 14:13:20 2016 Ronan Boiteau
** Last update Wed May 25 14:35:16 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static int	is_track_cleared(char *input)
{
  int		separator;
  int		idx;

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
	  free(get_next_line(STDIN));
	  my_printf("STOP_SIMULATION\n");
	  free(get_next_line(STDIN));
	  return (1);
	}
      ++idx;
    }
  return (0);
}

static int	is_dead_end(void)
{
  return (0);
}

int		is_end_of_track(void)
{
  char		*input;
  int		ret;

  input = get_next_line(STDIN);
  ret = (is_track_cleared(input) || is_dead_end() ? 1 : 0);
  free(input);
  return (ret);
}
