NAME	 = ai

IDIR	 = include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra -Wpedantic -Werror

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
