/*
** my_itoa.c for my_itoa in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Jan 27 02:23:39 2016 Ronan Boiteau
** Last update Tue Apr 12 23:18:34 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static char	_count_digits(int nbr, char isneg)
{
  if (nbr < 0)
    {
      isneg = 1;
      nbr = nbr * -1;
    }
  if (nbr < 10)
    return (1 + isneg);
  else if (nbr < 100)
    return (2 + isneg);
  else if (nbr < 1000)
    return (3 + isneg);
  else if (nbr < 10000)
    return (4 + isneg);
  else if (nbr < 100000)
    return (5 + isneg);
  else if (nbr < 1000000)
    return (6 + isneg);
  else if (nbr < 10000000)
    return (7 + isneg);
  else if (nbr < 100000000)
    return (8 + isneg);
  else if (nbr < 1000000000)
    return (9 + isneg);
  else
    return (10 + isneg);
}

static char	_nbr_isneg(int *nbr, char *str, int *idx, char *size)
{
  if (*nbr < 0)
    {
      *nbr = *nbr * -1;
      str[*idx] = '-';
      *idx += 1;
      *size -= 1;
      return (1);
    }
  return (0);
}

char		*my_itoa(int nbr)
{
  char		*str;
  char		size;
  int		idx;
  char		isneg;

  size = _count_digits(nbr, 0);
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx = 0;
  isneg = _nbr_isneg(&nbr, str, &idx, &size);
  str[idx] = '0';
  str[idx + 1] = '\0';
  while (size > 0)
    {
      str[idx] = ((nbr / my_power(10, size - 1))
		  - (my_atoi(str + isneg) * 10)) + '0';
      idx += 1;
      str[idx] = '\0';
      size -= 1;
    }
  return (str);
}
