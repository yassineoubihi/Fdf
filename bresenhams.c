/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:12:00 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/03 01:14:48 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	iso_helper(struct s_points **data, struct s_iso_index n)
{
	while (n.y_index < n.y)
	{
		while (n.x_index < n.x)
		{
			iso(&data[n.y_index][n.x_index].x, &data[n.y_index][n.x_index].y,
				data[n.y_index][n.x_index].z);
			n.x_index++;
		}
		n.x_index = 0;
		n.y_index++;
	}
}

void	iso_maker(struct s_points **data, int x, int y)
{
	struct s_iso_index	n;

	n.x_index = 0;
	n.y_index = 0;
	n.x = x;
	n.y = y;
	iso_helper(data, n);
	n.x_index = 0;
	n.y_index = 0;
	while (n.y_index < n.y)
	{
		while (n.x_index < n.x)
		{
			data[n.y_index][n.x_index].x += 1080 / 2;
			data[n.y_index][n.x_index].y += 1080 / 2;
			n.x_index++;
		}
		n.x_index = 0;
		n.y_index++;
	}
}

void	draw_line_loop(struct s_help_to_drwa var, int color, t_mlx *env,
	struct s_drawline_points draw_data)
{
	while (!(var.x == var.x1 && var.y == var.y1))
	{
		my_mlx_pixel_put(&env->img, var.x, var.y, color);
		draw_data.e2 = 2 * draw_data.error;
		if (draw_data.e2 >= draw_data.dy)
		{
			draw_data.error += draw_data.dy;
			var.x += draw_data.sx;
		}
		if (draw_data.e2 <= draw_data.dx)
		{
			draw_data.error += draw_data.dx;
			var.y += draw_data.sy;
		}
	}
}

void	drawline(struct s_help_to_drwa var, int color, t_mlx *env)
{
	struct s_drawline_points	draw_data;

	draw_data.dx = abs(var.x1 - var.x);
	if (var.x < var.x1)
		draw_data.sx = 1;
	else
		draw_data.sx = -1;
	draw_data.dy = -abs(var.y1 - var.y);
	if (var.y < var.y1)
		draw_data.sy = 1;
	else
		draw_data.sy = -1;
	draw_data.error = draw_data.dx + draw_data.dy;
	draw_line_loop(var, color, env, draw_data);
}
