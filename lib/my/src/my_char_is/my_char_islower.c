/*
** my_char_islower.c for my_char_islower in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:08:00 2015 Ronan Boiteau
** Last update Sun May 15 20:04:24 2016 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"

int		my_char_islower(const char letter)
{
  if (!(letter >= 'a' && letter <= 'z'))
    return (false);
  return (true);
}
