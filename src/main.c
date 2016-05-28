/*
** main.c for n4s in /home/boitea_r/c/CPE_2015_n4s
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed May  4 16:16:08 2016 Ronan Boiteau
** Last update Sat May 28 13:56:41 2016 Ronan Boiteau
*/

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

static void	print_grades(int *grades)
{
  int		idx;

  idx = 0;
  while (idx < NB_GRADES - 1)
    my_dprintf(STDERR, "%d - ", grades[idx++]);
  my_dprintf(STDERR, "\n");
  return ;
}

static void	my_putfloat(int fd, float nbr)
{
  int		idx;

  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_dprintf(fd, "-");
    }
  my_dprintf(fd, "%d", (int)nbr);
  my_dprintf(fd, ".");
  nbr -= (int)nbr;
  nbr *= 10;
  idx = 1;
  while ((int)nbr == 0 && idx < 6)
    {
      nbr *= 10;
      my_dprintf(fd, "0");
      ++idx;
    }
  my_dprintf(fd, "%d", (int)(nbr * my_power(10, 7 - idx - 1)));
  return ;
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

static void	adapt_speed(float speed)
{
  my_printf("CAR_FORWARD:");
  if (SPEED_FORMULA == 0)
    my_putfloat(STDOUT, 0.1);
  else if (SPEED_FORMULA > 0.5)
    my_putfloat(STDOUT, 0.8);
  else
    my_putfloat(STDOUT, SPEED_FORMULA);
  my_printf("\n");
  return ;
}

static int	change_direction(float *info)
{
  int		*grades;
  float		dir;

  if (!(grades = get_grades(info)))
    return (1);
  /* dprintf(STDERR, "middle - 1 -> %d\nmiddle -> %d\nmiddle + 1 -> %d\n", grades[NB_GRADES / 2 - 1], grades[NB_GRADES / 2], grades[NB_GRADES / 2 + 1]); */
  /* print_grades(grades); */
  if (grades[NB_GRADES / 2 - 1] > CRITIC
      && grades[NB_GRADES / 2] > CRITIC
      && grades[NB_GRADES / 2 + 1] > CRITIC)
    {
      if (grades[1] < CRITIC / 2)
	my_printf("WHEELS_DIR:-0.15\n");
      else if (grades[NB_GRADES - 2] < CRITIC / 2)
      	my_printf("WHEELS_DIR:0.15\n");
      else
	my_printf("WHEELS_DIR:0.0\n");
      if (is_end_of_track())
	return (1);
      adapt_speed(0.0);
      return (0);
    }
  dir = get_wheels_dir(grades);
  my_printf("WHEELS_DIR:");
  my_putfloat(STDOUT, dir);
  my_printf("\n");
  /* my_putfloat(STDERR, (dir > 1.0 ? 1.0 : dir)); */
  /* dprintf(STDERR, "\n"); */
  if (is_end_of_track())
    return (1);
  adapt_speed(dir < 0 ? dir * -1 : dir);
  return (0);
}

int		main(void)
{
  float		*info;

  my_printf("START_SIMULATION\n");
  if (is_end_of_track())
    return (EXIT_SUCCESS);
  my_printf("CAR_FORWARD:0.25\n");
  if (is_end_of_track())
    return (EXIT_SUCCESS);
  while (42)
    {
      if (!(info = get_info_lidar()))
	{
	  my_dprintf(STDERR, "Cannot get lidar data.\n");
	  return (EXIT_FAILURE);
	}
      if (change_direction(info) || is_end_of_track())
	return (EXIT_SUCCESS);
    }
}
