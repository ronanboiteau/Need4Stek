/*
** my_uitoa.c for my_uitoa in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan 31 17:50:05 2016 Ronan Boiteau
** Last update Tue Apr 12 23:23:34 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static char	_count_digits(t_uint nbr)
{
  if (nbr < 10)
    return (1);
  else if (nbr < 100)
    return (2);
  else if (nbr < 1000)
    return (3);
  else if (nbr < 10000)
    return (4);
  else if (nbr < 100000)
    return (5);
  else if (nbr < 1000000)
    return (6);
  else if (nbr < 10000000)
    return (7);
  else if (nbr < 100000000)
    return (8);
  else if (nbr < 1000000000)
    return (9);
  else
    return (10);
}

char		*my_uitoa(t_uint nbr)
{
  char		*str;
  char		size;
  int		idx;

  size = _count_digits(nbr);
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx = 0;
  str[idx] = '0';
  str[idx + 1] = '\0';
  while (size > 0)
    {
      str[idx] = ((nbr / my_power(10, size - 1))
		  - (my_atoi(str) * 10)) + '0';
      idx += 1;
      str[idx] = '\0';
      size -= 1;
    }
  return (str);
}
