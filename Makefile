##
## Makefile for n4s in /home/boitea_r/c/CPE_2015_n4s
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Wed May  4 16:15:12 2016 Ronan Boiteau
## Last update Sun May 29 22:25:25 2016 Ronan Boiteau
##

NAME	 = ia

IDIR	 = include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra -Wpedantic
CFLAGS	+= -Werror

SDIR	 = src/
SRCS	 = $(SDIR)end_of_track.c				\
	   $(SDIR)epur_raw_info.c				\
	   $(SDIR)get_info_lidar.c				\
	   $(SDIR)main.c					\
	   $(SDIR)my_putfloat.c

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f


all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
