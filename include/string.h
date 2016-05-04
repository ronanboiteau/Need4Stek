/*
** string.h for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Nov 10 16:11:56 2015 Ronan Boiteau
** Last update Tue Jan 19 23:29:10 2016 Ronan Boiteau
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct	s_string
{
  char		*str;
  unsigned int	idx;
}		t_string;

typedef struct	s_cstring
{
  const char	*str;
  unsigned int	idx;
}		t_cstring;

#endif /* !STRING_H_ */
