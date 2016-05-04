/*
** get_next_line.c for get_next_line in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Dec 21 03:02:16 2015 Ronan Boiteau
** Last update Tue Apr  5 15:55:10 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*my_strdup(const char *src)
{
  int		idx;
  char		*new_str;

  idx = 0;
  while (src != NULL && src[idx])
    idx += 1;
  if ((new_str = malloc(sizeof(char) * idx + 1)) == NULL)
    return (NULL);
  idx = 0;
  while (src[idx] != '\0')
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}

static char	*_str_cpy_cat(char *dest,
			      const char *src,
			      t_uint nbr,
			      int concatenate)
{
  t_uint	idx;
  t_uint	idx_src;

  idx = 0;
  if (concatenate == TRUE)
    {
      while (dest != NULL && dest[idx])
	idx += 1;
      idx_src = 0;
      while (src[idx_src] && idx_src < nbr)
	{
	  dest[idx] = src[idx_src];
	  idx += 1;
	  idx_src += 1;
	}
      dest[idx] = '\0';
      return (dest);
    }
  while (src[idx] && idx < nbr)
   {
      dest[idx] = src[idx];
      idx += 1;
    }
  dest[idx] = '\0';
  return (dest);
}

static char	*_auto_alloc(char *ptr, size_t mem)
{
  char		*new_ptr;
  int		ptr_len;

  ptr_len = 0;
  while (ptr != NULL && ptr[ptr_len])
    ptr_len += 1;
  if (ptr == NULL)
    {
      if ((new_ptr = malloc(sizeof(char) * mem)) == NULL)
	return (NULL);
      if (mem > 0)
	new_ptr[0] = '\0';
      return (new_ptr);
    }
  if ((new_ptr = malloc(sizeof(char) * (ptr_len + 1 + mem))) == NULL)
    return (NULL);
  new_ptr = _str_cpy_cat(new_ptr, ptr, ptr_len, FALSE);
  free(ptr);
  return (new_ptr);
}

static char	*_get_new_buffer(char *buf,
				 char *buf_full,
				 const int fd,
				 int eols)
{
  int		tmp;

  while (TRUE)
    {
      eols = 0;
      tmp = 0;
      while (buf_full != NULL && buf_full[tmp] && (tmp = tmp + 1))
      	{
      	  if (buf_full[tmp - 1] == '\n')
	    eols += 1;
      	}
      if (eols != 0)
	return (buf_full);
      if ((tmp = read(fd, buf, READ_SIZE)) <= 0 || (buf[tmp] = '\0')
	  || (buf_full = _auto_alloc(buf_full, READ_SIZE + 1)) == NULL)
      	{
	  if (buf_full != NULL && buf_full[0] != '\0')
	    return (buf_full);
	  free(buf);
	  free(buf_full);
      	  return (NULL);
      	}
      buf_full = _str_cpy_cat(buf_full, buf, READ_SIZE, TRUE);
    }
}

char		*get_next_line(const int fd)
{
  static char	*buffer;
  char		*buf;
  int		idx_buf;
  int		idx;
  char		*line;

  idx_buf = 0;
  if (READ_SIZE <= 0 || (buf = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL
      || (buffer = _get_new_buffer(buf, buffer, fd, 0)) == NULL)
    return (NULL);
  free(buf);
  idx = 0;
  while (buffer[idx_buf + idx] && buffer[idx_buf + idx] != '\n')
    idx += 1;
  while (buffer[idx_buf + idx] && buffer[idx_buf + idx] != '\n')
    idx += 1;
  buf = buffer;
  if ((line = _auto_alloc((line = NULL), idx + 2)) == NULL ||
      (buffer = buf[idx_buf + idx] == '\0' ? my_strdup("\0")
       : my_strdup(buf + idx_buf + idx + 1)) == NULL)
    return (NULL);
  line = _str_cpy_cat(line, buf + idx_buf, idx + 1, FALSE);
  line[idx] = '\0';
  free(buf);
  return (line);
}
