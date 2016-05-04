/*
** my_atof.c for my_atof in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu May  5 00:25:38 2016 Ronan Boiteau
** Last update Thu May  5 01:35:25 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static int	get_integer_part(const char *nbr)
{
  char		*integer_str;
  int		integer;
  int		idx;

  integer_str = my_strdup(nbr);
  idx = 0;
  while (integer_str[idx])
    {
      if (integer_str[idx] == '.')
	{
	  integer_str[idx] = '\0';
	  integer = my_atoi(integer_str);
	  free(integer_str);
	  return (integer);
	}
      ++idx;
    }
  integer = my_atoi(integer_str);
  free(integer_str);
  return (integer);
}

static char	*get_fractional_part(const char *nbr)
{
  char		*fractional;

  while (*nbr && *nbr != '.')
    ++nbr;
  if (*nbr != '.')
    return (NULL);
  fractional = my_strdup(++nbr);
  return (fractional);
}

static int	count_non_digits(const char *str)
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

float		my_atof(const char *str)
{
  float		nbr;
  char		*fractional;

  nbr = 0.0;
  nbr += get_integer_part(str);
  if ((fractional = get_fractional_part(str)))
    nbr += (float)my_atoi(fractional)
      / (float)my_power(10, my_strlen(fractional)
			- count_non_digits(fractional));
  free(fractional);
  return (nbr);
}
