/*
** my_power.c for my_power in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Nov  8 01:40:02 2015 Ronan Boiteau
** Last update Thu Dec 17 23:21:55 2015 Ronan Boiteau
*/

int		my_power(const int nbr, int power)
{
  if (power > 0)
    return (nbr * my_power(nbr, power - 1));
  else if (power == 0)
    return (1);
  return (0);
}
