/*
** my_printf.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov 14 08:17:53 2015 Ronan Boiteau
** Last update Sun May 29 23:04:57 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "printf_flags.h"
#include "printf_puts.h"

static t_uint	_if_not_flag(int fd, t_uint printed, t_cstring *str)
{
  int		space;

  while (str->str[str->idx] && str->str[str->idx] != '%')
    str->idx -= 1;
  printed += my_putchar_fd(fd, '%');
  str->idx += 1;
  space = FALSE;
  while (str->str[str->idx] && !_char_isletter(str->str[str->idx]))
    {
      if (str->str[str->idx] == ' ' && space == FALSE)
	{
	  printed += my_putchar_fd(fd, ' ');
	  space = TRUE;
	}
      str->idx += 1;
    }
  if (str->str[str->idx] && str->str[str->idx] != '%')
    printed += my_putchar_fd(fd, str->str[str->idx]);
  str->idx -= 1;
  return (printed);
}

static t_uint	_flags_handler(int fd,
			       t_flag *flags,
			       t_cstring *str,
			       va_list ap)
{
  const char	*specifiers;
  int		idx;
  t_uint	printed;

  printed = 0;
  specifiers = _find_flag(str, &printed, fd, ap);
  if (specifiers == NULL)
    return (-1);
  idx = _char_isflag(str->str[str->idx + 1], flags);
  if (idx == -1)
    printed += _if_not_flag(fd, 0, str);
  else
    printed = flags[idx].fct(fd, printed, ap);
  str->idx += 1;
  return (printed);
}

int		my_dprintf(int fd, const char *format, ...)
{
  va_list	ap;
  t_uint	printed;
  t_cstring	str;
  t_flag	flags[FLAGS_NBR];

  printed = 0;
  _init_structures(flags, &str, format);
  va_start(ap, format);
  if (str.str == NULL)
    return (-1);
  while (str.str[str.idx] != '\0')
    {
      if (str.str[str.idx] != '%')
	printed += my_putchar_fd(fd, str.str[str.idx]);
      else if (str.str[str.idx] == '%' && str.str[str.idx + 1] == '\0')
	return (-1);
      else if (str.str[str.idx] == '%' && str.str[str.idx + 1])
	printed += _flags_handler(fd, flags, &str, ap);
      str.idx += 1;
    }
  va_end(ap);
  return (printed);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  t_uint	printed;
  t_cstring	str;
  t_flag	flags[FLAGS_NBR];

  printed = 0;
  _init_structures(flags, &str, format);
  va_start(ap, format);
  if (str.str == NULL)
    return (-1);
  while (str.str[str.idx] != '\0')
    {
      if (str.str[str.idx] != '%')
	printed += my_putchar_fd(STDOUT, str.str[str.idx]);
      else if (str.str[str.idx] == '%' && str.str[str.idx + 1] == '\0')
	return (-1);
      else if (str.str[str.idx] == '%' && str.str[str.idx + 1])
	printed += _flags_handler(STDOUT, flags, &str, ap);
      str.idx += 1;
    }
  va_end(ap);
  return (printed);
}
