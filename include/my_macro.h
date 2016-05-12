/*
** my_macro.h for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct 27 14:04:25 2015 Ronan Boiteau
** Last update Thu Feb  4 17:19:22 2016 Ronan Boiteau
*/

#ifndef MY_MACRO_H_
# define MY_MACRO_H_

# define ABS(nbr)		(nbr < 0 ? -nbr : nbr)
# define MAX(nbr_1, nbr_2)	(nbr_1 < nbr_2 ? nbr_2 : nbr_1)
# define MIN(nbr_1, nbr_2)	(nbr_1 > nbr_2 ? nbr_2 : nbr_1)

# define FALSE	(0)
# define TRUE	(1)

# define STDIN	(0)
# define STDOUT	(1)
# define STDERR	(2)

# define C_NUL	'\0'
# define EOT	4
# define C_TAB	'\t'
# define C_EOL	'\n'

# define NUL	"\0"
# define TAB	"\t"
# define EOL	"\n"

#endif /* !MY_MACRO_H_ */
