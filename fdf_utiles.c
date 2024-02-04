/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:13:59 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/04 15:40:10 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**free_mem_splite(char **tab)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (NULL);
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
	result = free_mem_splite(result);
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

void	map_check(char *map)
{
	struct s_map_check	vars;

	vars.error = 0;
	check_name(map);
	vars.fd = open(map, O_RDONLY);
	if (vars.fd == -1)
		exit(1);
	vars.s = get_next_line(vars.fd);
	if (!vars.s || vars.s[0] == '\n')
		exit(1);
	while (vars.s && vars.error < 1)
	{
		if (vars.s[0] == '\n')
			vars.error++;
		if (vars.error >= 1)
		{
			free(vars.s);
			exit(1);
		}
		free(vars.s);
		vars.s = get_next_line(vars.fd);
	}
	free(vars.s);
	close(vars.fd);
}
