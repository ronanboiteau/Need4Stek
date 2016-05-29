/*
** my.h for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  8 10:33:26 2015 Ronan Boiteau
** Last update Sun May 29 23:12:42 2016 Ronan Boiteau
*/

#ifndef MY_H_
# define MY_H_

# include "my_macro.h"
# include "my_typedef.h"

char	*get_next_line(int const fd);
int	match(char *str1, char *str2);
float	my_atof(const char *str);
int	my_atoi(const char *str);
int	my_char_isalpha(const char letter);
int	my_char_islower(const char letter);
int	my_char_isnum(const char letter);
int	my_char_isprintable(const char letter);
int	my_char_isupper(const char letter);
int	my_cmp(const char *str1, const char *str2);
int	my_dprintf(int fd, const char *format, ...);
void	my_free_2d_tab(char **tab);
int	my_power(const int nbr, int power);
int	my_printf(const char *format, ...);
int	my_str_isnum(const char *str);
int	my_strcmp(const char *str1, const char *str2);
char	*my_strdup(const char *src);
int	my_strlen(const char *str);
char	*my_strncat(char *dest, const char *src, int nbr);
int	my_strncmp(const char *str1, const char *str2, t_uint nbr);
char	*my_strncpy(char *dest, const char *src, t_uint nbr);
char	*my_strstr(char *str, const char *to_find);
int	nmatch(char *str1, char *str2);

#endif /* !MY_H_ */
