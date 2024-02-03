/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/02 23:31:05 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zed_high_helper(struct s_draw_param param, struct s_points **data,
		t_mlx *env)
{
	struct s_help_to_drwa	var;

	var.x = data[param.y][param.x].x;
	var.y = data[param.y][param.x].y;
	var.x1 = data[param.y][param.x + 1].x;
	var.y1 = data[param.y][param.x + 1].y;
	drawline(var, data[param.y][param.x].color, env);
	var.x1 = data[param.y + 1][param.x].x;
	var.y1 = data[param.y + 1][param.x].y;
	drawline(var, data[param.y][param.x].color, env);
}

void	zed_high_helper_second(struct s_draw_param param,
		struct s_points **data, t_mlx *env)
{
	struct s_help_to_drwa	var;

	var.x = data[param.y][param.x].x;
	var.y = data[param.y][param.x].y;
	var.x1 = data[param.y][param.x + 1].x;
	var.y1 = data[param.y][param.x + 1].y;
	if (param.x < data[0][0].max_x - 1)
	{
		if (param.x > 0)
			drawline(var, data[param.y][param.x].color, env);
		else
			drawline(var, data[param.y][param.x].color, env);
	}
	if (param.y < data[0][0].max_y - 1)
	{
		var.x1 = data[param.y + 1][param.x].x;
		var.y1 = data[param.y + 1][param.x].y;
		if (param.y > 0)
			drawline(var, data[param.y][param.x].color, env);
		else
			drawline(var, data[param.y][param.x].color, env);
	}
}

void	zed_high(struct s_draw_param param, struct s_points **data, t_mlx *env)
{
	if ((param.x < data[0][0].max_x - 1) && (param.y < data[0][0].max_y - 1))
	{
		zed_high_helper(param, data, env);
	}
	else
	{
		zed_high_helper_second(param, data, env);
	}
}

void	zed_low(struct s_draw_param param, struct s_points **data, t_mlx *env)
{
	struct s_help_to_drwa	var;

	var.x = data[param.y][param.x].x;
	var.y = data[param.y][param.x].y;
	var.x1 = data[param.y][param.x + 1].x;
	var.y1 = data[param.y][param.x + 1].y;
	if ((param.x < data[0][0].max_x - 1) && (param.y < data[0][0].max_y - 1))
	{
		drawline(var, 16777215, env);
		var.x1 = data[param.y + 1][param.x].x;
		var.y1 = data[param.y + 1][param.x].y;
		drawline(var, 16777215, env);
	}
	else
	{
		var.x1 = data[param.y][param.x + 1].x;
		var.y1 = data[param.y][param.x + 1].y;
		if (param.x < data[0][0].max_x - 1)
			drawline(var, 16777215, env);
		var.x1 = data[param.y + 1][param.x].x;
		var.y1 = data[param.y + 1][param.x].y;
		if (param.y < data[0][0].max_y - 1)
			drawline(var, 16777215, env);
	}
}

void	draw(struct s_points **data, char *argv, t_mlx *env)
{
	struct s_draw_param	param;
	int					x;
	int					fd;

	param.x = 0;
	param.y = 0;
	x = 0;
	fd = open("test_maps/test.fdf", O_RDWR);
	while (param.y < data[0][0].max_y)
	{
		while (param.x < data[0][0].max_x)
		{
			if (data[param.y][param.x].z > 0 || data[param.y][param.x].z < 0)
				zed_high(param, data, env);
			else
				zed_low(param, data, env);
			param.x++;
		}
		param.x = 0;
		param.y++;
	}
}
