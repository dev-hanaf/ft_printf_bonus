CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs 

SRC = ft_printf.c \
		ft_dicimal.c \
		ft_utils.c \
		ft_precision.c \
		count_val_flags.c  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re : fclean all

.PHONY: all clean fclean re