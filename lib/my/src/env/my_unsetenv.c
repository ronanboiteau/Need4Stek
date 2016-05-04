/*
** my_unsetenv.c for my_unsetenv in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan  3 19:28:43 2016 Ronan Boiteau
** Last update Tue Apr 12 23:20:09 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

static t_uint	_get_var_pos(char **env, char *to_unset)
{
  t_uint	pos;

  pos = 0;
  while (env != NULL && env[pos])
    {
      if (my_strncmp(env[pos], to_unset, my_strlen(to_unset)) == 0)
	return (pos);
      pos += 1;
    }
  return (pos);
}

void		my_unsetenv(char ***env, char *to_unset)
{
  t_uint	idx;
  t_uint	to_unset_pos;
  char		**new_env;

  new_env = *env;
  to_unset_pos = _get_var_pos(new_env, to_unset);
  if (my_getenv(new_env, to_unset) == NULL)
    return ;
  idx = 0;
  while (new_env[idx] && idx != to_unset_pos)
    idx += 1;
  while (new_env[idx])
    {
      free(new_env[idx]);
      new_env[idx] = my_strdup(new_env[idx + 1]);
      idx += 1;
    }
  new_env[idx] = '\0';
  return ;
}
