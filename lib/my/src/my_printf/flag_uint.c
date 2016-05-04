/*
** flag_uint.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov  7 14:34:41 2015 Ronan Boiteau
** Last update Sun Jan 17 16:24:05 2016 Ronan Boiteau
*/

#include "my.h"
#include "printf_flags.h"
#include "printf_puts.h"

t_uint	_convert_binary(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, t_uint), "01");
  return (printed);
}

t_uint	_convert_decimal(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, t_uint), "0123456789");
  return (printed);
}

t_uint	_convert_hex_lowcase(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, t_uint), "0123456789abcdef");
  return (printed);
}

t_uint	_convert_hex_upcase(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, t_uint), "0123456789ABCDEF");
  return (printed);
}

t_uint	_convert_octal(int fd, t_uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, t_uint), "01234567");
  return (printed);
}
