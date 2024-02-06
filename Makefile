# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 09:11:59 by youbihi           #+#    #+#              #
#    Updated: 2024/02/06 09:12:01 by youbihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF = main.c fdf.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c fdf_utiles.c bresenhams.c ft_atoi_hex.c ft_atoi_hex_utils.c bresenhams_utiles.c fill_data.c fdf_utiles_helper.c ft_atoi.c ft_strlen.c ft_tolower.c ft_isdigit.c ft_split.c
OBJF = $(SRCF:.c=.o)
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra
FDF = fdf

all: $(FDF)

$(FDF): $(LIBFT) $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o $(FDF) -lmlx -framework OpenGL -framework AppKit

%.o: %.c fdf.h
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(FDF)

re: fclean all
