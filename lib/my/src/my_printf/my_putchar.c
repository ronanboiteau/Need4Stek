/*
** my_putchar.c for my_putchar in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 09:33:09 2015 Ronan Boiteau
** Last update Thu Feb  4 19:17:18 2016 Ronan Boiteau
*/

#include "my.h"
#include <unistd.h>

t_uint		my_putchar_fd(int fd, const char letter)
{
  write(fd, &letter, 1);
  return (1);
}

t_uint		my_putchar(const char letter)
{
  my_putchar_fd(1, letter);
  return (1);
}
