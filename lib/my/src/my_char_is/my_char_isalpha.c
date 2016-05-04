/*
** my_char_isalpha.c for my_char_isalpha in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:06:02 2015 Ronan Boiteau
** Last update Thu Dec 17 22:58:31 2015 Ronan Boiteau
*/

#include "my.h"

int		my_char_isalpha(const char letter)
{
  if (!((letter >= 'A' && letter <= 'Z') ||
	(letter >= 'a' && letter <= 'z') ||
	(letter >= '0' && letter <= '9')))
    return (FALSE);
  return (TRUE);
}
