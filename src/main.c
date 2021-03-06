#include <stdlib.h>
#include "my.h"
#include "n4s_algo.h"
#include "n4s_lidar.h"

static int	*get_grades(float *info)
{
  int		*grades;
  int		idx_grades;
  int		idx_info;
  int		tmp;

  if (!(grades = malloc(sizeof(int) * NB_GRADES)))
    return (NULL);
  idx_grades = 0;
  idx_info = 0;
  while (idx_info + NB_RADIUS < NB_LIDAR_VALUES)
    {
      grades[idx_grades] = 0;
      tmp = 0;
      while (tmp < NB_RADIUS)
	{
	  grades[idx_grades] += (int)info[idx_info + tmp];
	  ++tmp;
	}
      grades[idx_grades] = grades[idx_grades] / 3;
      ++idx_grades;
      ++idx_info;
    }
  return (grades);
}

static float	get_wheels_dir(int *grades)
{
  int		idx;
  int		greatest[2];

  idx = 0;
  greatest[POS] = idx;
  greatest[GRADE] = grades[idx++];
  while (idx < NB_GRADES - 1)
    {
      if (grades[idx] > greatest[GRADE])
	{
	  greatest[POS] = idx;
	  greatest[GRADE] = grades[idx];
	}
      ++idx;
    }
  if (((((float)greatest[POS]) / (float)NB_GRADES) * 2.0) - 1 == -1)
    return (1.0);
  return (1.0 / ((((float)greatest[POS]) / (float)NB_GRADES) * 2.0) - 1);
}

static void	adapt_speed(float speed, float dir)
{
  my_printf("CAR_FORWARD:");
  if (SPEED_FORMULA == 0)
    my_putfloat(STDOUT, 0.1);
  else
    my_putfloat(STDOUT, SPEED_FORMULA * (dir == 0.0 ? 1.0 : 1.0 / dir));
  my_printf("\n");
  return ;
}

static int	change_direction(float *info, float *last_dir)
{
  int		*grades;
  float		dir;

  if (!(grades = get_grades(info)))
    return (1);
  if (grades[NB_GRADES / 2 - 1] > CRITIC && grades[NB_GRADES / 2] > CRITIC
      && grades[NB_GRADES / 2 + 1] > CRITIC)
    {
      if (grades[1] < CRITIC / 2)
	dir = -0.05;
      else if (grades[NB_GRADES - 2] < CRITIC / 2)
	dir = 0.05;
      else
	dir = 0.00;
    }
  else
    dir = get_wheels_dir(grades);
  my_printf("WHEELS_DIR:");
  my_putfloat(STDOUT, dir);
  my_printf("\n");
  if (is_end_of_track(info))
    return (1);
  adapt_speed((dir < 0 ? dir * -1 : dir), *last_dir);
  *last_dir = dir;
  return (0);
}

int		main(void)
{
  float		*info;
  float		last_dir;

  last_dir = 0.0;
  my_printf("START_SIMULATION\n");
  if (is_end_of_track(NULL))
    return (EXIT_SUCCESS);
  my_printf("CAR_FORWARD:0.05\n");
  if (is_end_of_track(NULL))
    return (EXIT_SUCCESS);
  while (42)
    {
      if (!(info = get_info_lidar()))
	{
	  my_dprintf(STDERR, "Cannot get lidar data.\n");
	  return (EXIT_FAILURE);
	}
      if (change_direction(info, &last_dir) || is_end_of_track(info))
	return (EXIT_SUCCESS);
    }
}
