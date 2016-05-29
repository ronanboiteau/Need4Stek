/*
** my_atoi.c for my_atoi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Dec 18 02:12:36 2015 Ronan Boiteau
** Last update Sun May 29 23:03:42 2016 Ronan Boiteau
*/

#include <limits.h>
#include "my.h"

static int	_skip_letters(const char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] && str[idx] != '-' && str[idx] != '+' &&
	 (str[idx] < '0' || str[idx] > '9'))
    idx += 1;
  while ((str[idx + 1] && (str[idx + 1] == '-' || str[idx + 1] == '+'))
	 || str[idx] == '+')
    idx += 1;
  return (idx);
}

static int	_set_reverser(const char *str, int *idx)
{
  if (str[*idx] == '-')
    {
      *idx += 1;
      return (-1);
    }
  return (1);
}

int		my_atoi(const char *str)
{
  t_ll		result;
  int		reverser;
  int		idx;
  int		lenght;

  if (!my_str_isnum(str))
    return (-1);
  result = 0;
  idx = _skip_letters(str);
  reverser = _set_reverser(str, &idx);
  lenght = idx;
  while (str[lenght] >= '0' && str[lenght] <= '9')
    lenght += 1;
  while (idx < lenght)
    {
      result = result + (t_ll)((str[idx] - '0') *
			       my_power(10, lenght - idx - 1));
      if (result < INT_MIN || result - 1 > INT_MAX)
	return (-1);
      idx += 1;
    }
  result *= reverser;
  return ((int)result);
}
