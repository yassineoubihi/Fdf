SRCF = main.c fdf.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c fdf_utiles.c bresenhams.c ft_atoi_hex.c ft_atoi_hex_utils.c bresenhams_utiles.c fill_data.c fdf_utiles_helper.c
RM = rm -f
CC = cc
CFLAGS =
FDF = fdf
LIBFT = libft/libft.a

all: $(FDF)

$(LIBFT):
	make -C ./libft

$(FDF): $(LIBFT) $(SRCF)
	$(CC) $(CFLAGS) $(SRCF) -o $(FDF) -L./libft -lft -lmlx -framework OpenGL -framework AppKit
	make -C ./libft

clean:
	$(RM) $(FDF)
	make -C ./libft clean

fclean: clean
	$(RM) $(FDF)
	make -C ./libft fclean

re: fclean all
