/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:48:07 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/06 09:07:52 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(0.1) + *z * sin(0.1);
	*z = -previous_y * sin(0.1) + *z * cos(0.1);
}

void	rotate_y(int *x, int *z)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(0.1) + *z * sin(0.1);
	*z = -previous_x * sin(0.1) + *z * cos(0.1);
}

void	rotate_z(int *x, int *y)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(0.1) - previous_y * sin(0.1);
	*y = previous_x * sin(0.1) + previous_y * cos(0.1);
}

void	change_data(struct s_points **data)
{
	int	x;
	int	y;
	int	x_index;
	int	y_index;

	x = 0;
	y = 0;
	x_index = 0;
	y_index = 0;
	while (y_index < data[0][0].max_y)
	{
		while (x_index < data[0][0].max_x)
		{
			rotate_x(&data[y_index][x_index].y, &data[y_index][x_index].z);
			rotate_y(&data[y_index][x_index].x, &data[y_index][x_index].z);
			rotate_z(&data[y_index][x_index].x, &data[y_index][x_index].y);
			x_index++;
		}
		x_index = 0;
		y_index++;
	}
}

void	check_name(char *map)
{
	int		i;
	int		len;
	char	*s;

	i = 3;
	s = ".fdf";
	len = ft_strlen(map) - 1;
	while (i >= 0)
	{
		if (map[len] != s[i])
			exit(1);
		len--;
		i--;
	}
}
