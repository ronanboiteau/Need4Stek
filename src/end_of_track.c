#include <stdlib.h>
#include "my.h"
#include "n4s_algo.h"

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

static int	is_dead_end(float *info)
{
  int		idx;

  idx = 0;
  while (info[idx])
    {
      if (info[idx] > CRASHED)
	return (0);
      ++idx;
    }
  my_printf("CAR_FORWARD:0.0\n");
  free(get_next_line(STDIN));
  my_printf("STOP_SIMULATION\n");
  free(get_next_line(STDIN));
  return (1);
}

int		is_end_of_track(float *info)
{
  char		*input;
  int		ret;

  input = get_next_line(STDIN);
  if (input == NULL)
    {
      my_printf("CAR_FORWARD:0.0\n");
      free(get_next_line(STDIN));
      my_printf("STOP_SIMULATION\n");
      free(get_next_line(STDIN));
      return (1);
    }
  ret = is_track_cleared(input);
  if (!ret && info)
    ret += is_dead_end(info);
  free(input);
  return (ret > 0 ? 1 : 0);
}
