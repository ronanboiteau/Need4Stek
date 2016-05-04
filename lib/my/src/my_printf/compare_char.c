/*
** compare_char.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov 14 08:22:26 2015 Ronan Boiteau
** Last update Thu Dec 17 23:01:27 2015 Ronan Boiteau
*/

#include "my.h"
#include "printf_flags.h"

int		_char_isflag(const char letter, const t_flag *flags)
{
  int		idx;

  idx = 0;
  while (idx < FLAGS_NBR)
    {
      if (letter == flags[idx].flag_char)
	return (idx);
      idx += 1;
    }
  return (-1);
}

int		_char_isletter(const char letter)
{
  if ((letter >= 'a' && letter <= 'z') ||
      (letter >= 'A' && letter <= 'Z') ||
      letter == '/' || letter == '{' ||
      letter == '\n' || letter == '%' ||
      letter == '}' || letter == '=' ||
      letter == ':' || letter == ',' ||
      letter == ';' || letter == '[' ||
      letter == ']' || letter == '(' ||
      letter == ')' || letter == 'l')
    return (TRUE);
  return (FALSE);
}
