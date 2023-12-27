CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs 

SRC = ft_printf.c \
		ft_dicimal.c \
		ft_utils.c \
		count_val_flags.c  \
		ft_putchar.c \
		rond_point.c \
		ft_minus.c\
		ft_width.c\
		ft_parser.c\
		ft_get_precision.c ft_precision.c ft_zero.c ft_format.c \
		ft_mandatory_flags.c \
		rond_point_u.c ft_precision_u.c ft_putnbr_u
		
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