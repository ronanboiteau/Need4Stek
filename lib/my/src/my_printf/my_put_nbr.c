/*
** my_put_nbr.c for my_put_nbr.c in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 09:33:53 2015 Ronan Boiteau
** Last update Sun Jan 17 16:25:04 2016 Ronan Boiteau
*/

#include "my.h"
#include "printf_puts.h"

t_uint		my_put_nbr_fd(int fd, int nbr)
{
  t_uint	printed;

  printed = 0;
  if (nbr == -2147483648)
    {
      printed += my_putstr_fd(fd, "-2147483648");
      return (11);
    }
  if (nbr < 0)
    {
      my_putchar_fd(fd, '-');
      printed += 1;
      nbr = nbr * -1;
    }
  if (nbr >= 10)
    {
      printed += my_put_nbr_fd(fd, nbr / 10);
      my_putchar_fd(fd, nbr % 10 + '0');
      printed += 1;
    }
  else
    printed += my_putchar_fd(fd, nbr + '0');
  return (printed);
}

t_uint		my_putnbr_printf(int fd, int nbr)
{
  t_uint	printed;

  printed = 0;
  if (nbr == -2147483648)
    {
      printed += my_putstr_fd(fd, "-2147483648");
      return (printed);
    }
  if (nbr < 0)
    {
      printed += my_putchar_fd(fd, '-');
      nbr = nbr * -1;
    }
  printed += my_put_nbr_fd(fd, nbr);
  return (printed);
}
