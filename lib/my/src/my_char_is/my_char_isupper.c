/*
** my_char_isupper.c for my_char_isupper in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:09:28 2015 Ronan Boiteau
** Last update Sun May 15 20:05:07 2016 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"

int		my_char_isupper(const char letter)
{
  if (!(letter >= 'A' && letter <= 'Z'))
    return (false);
  return (true);
}
