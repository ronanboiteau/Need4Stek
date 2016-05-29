/*
** my_char_isnum.c for my_char_isnum in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:08:36 2015 Ronan Boiteau
** Last update Sun May 15 20:05:11 2016 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"

int		my_char_isnum(const char letter)
{
  if (!(letter >= '0' && letter <= '9'))
    return (false);
  return (true);
}
