/*
** my_swap.c for my_swap in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  1 08:58:07 2015 Ronan Boiteau
** Last update Sun Nov  8 02:04:48 2015 Ronan Boiteau
*/

void		my_swap(int *ptr_a, int *ptr_b)
{
  int		tmp;

  tmp = *ptr_a;
  *ptr_a = *ptr_b;
  *ptr_b = tmp;
  return ;
}
