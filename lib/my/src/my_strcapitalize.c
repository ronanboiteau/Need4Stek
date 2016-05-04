/*
** my_strcapitalize.c for my_strcapitalize in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 17:22:33 2015 Ronan Boiteau
** Last update Sun Jan 17 16:51:14 2016 Ronan Boiteau
*/

#include "my.h"

char		*my_strcapitalize(char *str)
{
  t_uint	idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (my_char_isalpha(str[idx]) == 0 || idx == 0)
	{
	  while (my_char_isalpha(str[idx]) == 0)
	    idx += 1;
	  if (my_char_islower(str[idx]))
	    str[idx] = str[idx] - 32;
	}
      idx += 1;
    }
  return (str);
}
