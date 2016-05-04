##
## Makefile for libmy in /home/boitea_r
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Tue Nov 10 15:47:58 2015 Ronan Boiteau
## Last update Sun Jan 31 17:55:04 2016 Ronan Boiteau
##

IDIR	 = include/
INC	 = $(IDIR)colors.h				\
	  $(IDIR)get_next_line.h			\
	  $(IDIR)my.h					\
	  $(IDIR)my_macro.h				\
	  $(IDIR)my_typedef.h				\
	  $(IDIR)printf_flags.h				\
	  $(IDIR)printf_puts.h				\
	  $(IDIR)string.h

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

RM	 = rm -f

NAME	 = ../libmy.a

SDIR	 = src/
SRCS	 = $(SDIR)env/my_envcpy.c			\
	  $(SDIR)env/my_getenv.c			\
	  $(SDIR)env/my_printenv.c			\
	  $(SDIR)env/my_setenv.c			\
	  $(SDIR)env/my_unsetenv.c			\
	  $(SDIR)get_next_line.c			\
	  $(SDIR)match.c				\
	  $(SDIR)my_atoi.c				\
	  $(SDIR)my_char_is/my_char_isalpha.c		\
	  $(SDIR)my_char_is/my_char_islower.c		\
	  $(SDIR)my_char_is/my_char_isnum.c		\
	  $(SDIR)my_char_is/my_char_isprintable.c	\
	  $(SDIR)my_char_is/my_char_isupper.c		\
	  $(SDIR)my_cmp.c				\
	  $(SDIR)my_epur_str.c				\
	  $(SDIR)my_find_prime_sup.c			\
	  $(SDIR)my_free_2d_tab.c			\
	  $(SDIR)my_is_prime.c				\
	  $(SDIR)my_itoa.c				\
	  $(SDIR)my_max_int_tab.c			\
	  $(SDIR)my_min_int_tab.c			\
	  $(SDIR)my_printf/compare_char.c		\
	  $(SDIR)my_printf/my_printf.c			\
	  $(SDIR)my_printf/find_flag.c			\
	  $(SDIR)my_printf/flag_char.c			\
	  $(SDIR)my_printf/flag_int.c			\
	  $(SDIR)my_printf/flag_ptr.c			\
	  $(SDIR)my_printf/flag_str.c			\
	  $(SDIR)my_printf/flag_uint.c			\
	  $(SDIR)my_printf/init.c			\
	  $(SDIR)my_printf/my_putchar.c			\
	  $(SDIR)my_printf/my_putnbr_base.c		\
	  $(SDIR)my_printf/my_put_nbr.c			\
	  $(SDIR)my_printf/my_putstr.c			\
	  $(SDIR)my_printf/my_showstr.c			\
	  $(SDIR)my_power.c				\
	  $(SDIR)my_revstr.c				\
	  $(SDIR)my_sort_int_tab.c			\
	  $(SDIR)my_square_root.c			\
	  $(SDIR)my_str_is/my_str_isalpha.c		\
	  $(SDIR)my_str_is/my_str_islower.c		\
	  $(SDIR)my_str_is/my_str_isnum.c		\
	  $(SDIR)my_str_is/my_str_isprintable.c		\
	  $(SDIR)my_str_is/my_str_isupper.c		\
	  $(SDIR)my_strcapitalize.c			\
	  $(SDIR)my_strcmp.c				\
	  $(SDIR)my_strdup.c				\
	  $(SDIR)my_strlen.c				\
	  $(SDIR)my_strlowcase.c			\
	  $(SDIR)my_strncat.c				\
	  $(SDIR)my_strncmp.c				\
	  $(SDIR)my_strncpy.c				\
	  $(SDIR)my_strstr.c				\
	  $(SDIR)my_str_to_wordtab.c			\
	  $(SDIR)my_strupcase.c				\
	  $(SDIR)my_swap.c				\
	  $(SDIR)my_uitoa.c				\
	  $(SDIR)nmatch.c

OBJS	 = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	cp $(INC) ../../$(IDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
