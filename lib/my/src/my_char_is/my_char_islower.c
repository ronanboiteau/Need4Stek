/*
** my_char_islower.c for my_char_islower in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:08:00 2015 Ronan Boiteau
** Last update Thu Dec 17 22:58:26 2015 Ronan Boiteau
*/

#include "my.h"

int		my_char_islower(const char letter)
{
  if (!(letter >= 'a' && letter <= 'z'))
    return (FALSE);
  return (TRUE);
}
