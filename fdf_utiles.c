/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:13:59 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/03 01:13:47 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**handel_line(char *argv, int x)
{
	int		fd;
	char	**r;
	char	*s;

	fd = open(argv, O_RDONLY);
	s = get_next_line(fd);
	r = ft_split(s, ' ');
	return (r);
}

int	count_x_rows(char *s)
{
	int		i;
	int		x;
	char	**result;

	result = ft_split(s, ' ');
	i = 0;
	x = 0;
	while (result[i] != NULL)
	{
		x++;
		i++;
	}
	return (x);
}

void	count_rows_coluns(int *x, int *y, char *argv)
{
	char	*s;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	i = 0;
	*x = 0;
	*y = 0;
	s = get_next_line(fd);
	while (s != NULL)
	{
		*x = count_x_rows(s);
		i++;
		(*y)++;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	s = NULL;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (0 < x && x < 1080 && 0 < y && y < 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}
