/*
** my_char_isprintable.c for my_char_isprintable in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:11:26 2015 Ronan Boiteau
** Last update Sun May 15 20:05:16 2016 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"

int		my_char_isprintable(const char letter)
{
  if (!((letter >= 32 && letter <= 126) || letter == '\0'
	|| (letter >= 7 && letter <= 13)))
    return (false);
  return (true);
}
