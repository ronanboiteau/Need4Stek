/*
** flag_int.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov  7 04:20:32 2015 Ronan Boiteau
** Last update Sun Jan 17 16:23:45 2016 Ronan Boiteau
*/

#include "my.h"
#include "printf_flags.h"
#include "printf_puts.h"

t_uint	_print_int(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_printf(fd, va_arg(ap, int));
  return (printed);
}
