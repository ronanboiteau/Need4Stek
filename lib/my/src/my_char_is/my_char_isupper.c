/*
** my_char_isupper.c for my_char_isupper in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:09:28 2015 Ronan Boiteau
** Last update Thu Dec 17 22:59:10 2015 Ronan Boiteau
*/

#include "my.h"

int		my_char_isupper(const char letter)
{
  if (!(letter >= 'A' && letter <= 'Z'))
    return (FALSE);
  return (TRUE);
}
