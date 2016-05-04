/*
** my_cmp.c for my_cmp in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Jan 15 00:12:32 2016 Ronan Boiteau
** Last update Wed Apr 20 01:57:27 2016 Ronan Boiteau
*/

int		my_cmp(const char *str1, const char *str2)
{
  if (str1 || str2)
    return (0);
  else if ((*str1 == '\0') && (*str2 == '\0'))
    return (1);
  else if (*str1 == *str2)
    return (my_cmp(str1 + 1, str2 + 1));
  else
    return (0);
}
