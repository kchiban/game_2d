NAME = so_long

SRC = so_long.c check_wall.c \
	utils.c moves.c ft_split.c image.c \
	parsing.c print_error.c check_map.c  check_path.c \
	getline/get_next_line.c check_map_items.c \
	getline/get_next_line_utils.c \
	f_printf/ft_putstr.c f_printf/ft_putnbr.c f_printf/ft_putchar.c \
	f_printf/ft_printf.c f_printf/ft_hexnum.c f_printf/ft_uphexnum.c \
	f_printf/ft_unsnum.c f_printf/ft_print_ptr.c \

	

CC = CC

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
