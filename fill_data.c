/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:49:54 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/04 14:15:48 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_habdel(struct s_points *data, char *s, int x, int y)
{
	char	**r;

	r = ft_split(s, ',');
	data->screen_x = 1080;
	data->screen_y = 1080;
	data->the_min = min_calcul((data->screen_x / data->max_x / 2),
			(data->screen_y / data->max_y / 2));
	data->x = x * data->the_min;
	data->y = y * data->the_min;
	data->z = ft_atoi(r[0]);
	data->color = ft_atoi_hex(r[1]);
	r = free_mem_splite(r);
}

void	no_color_habdel(struct s_points *data, char *s, int x, int y)
{
	data->screen_x = 1080;
	data->screen_y = 1080;
	data->the_min = min_calcul((data->screen_x / data->max_x / 2),
			(data->screen_y / data->max_y / 2));
	data->x = x * data->the_min;
	data->y = y * data->the_min;
	data->z = ft_atoi(s);
	if (data->z > 0 || data->z < 0)
		data->color = 16766720;
	else
		data->color = 16777215;
}

void	x_loop(struct s_fill_index fill,
	struct s_points **data, struct s_data_fill data_fill)
{
	while (fill.x_index < data[0][0].max_x)
	{
		data[fill.y_index][fill.x_index].max_x = data_fill.x;
		data[fill.y_index][fill.x_index].max_y = data_fill.y;
		if (data_fill.r != NULL && data_fill.r[fill.x_index] != NULL
			&&data_fill.r[fill.x_index + 1] != NULL
			&& ft_custom_strchr(data_fill.r[fill.x_index]) == 1)
			color_habdel(&data[fill.y_index][fill.x_index],
				data_fill.r[fill.x_index],
				fill.x_index, fill.y_index);
		else if (data_fill.r != NULL && data_fill.r[fill.x_index] != NULL)
			no_color_habdel(&data[fill.y_index][fill.x_index],
				data_fill.r[fill.x_index], fill.x_index, fill.y_index);
		fill.x_index++;
	}
}

void	fill_data(struct s_points **data, int x, int y, char *argv)
{
	struct s_data_fill	data_fill;
	struct s_fill_index	fill;

	fill.x_index = 0;
	fill.y_index = 0;
	data_fill.x = x;
	data_fill.y = y;
	data_fill.fd = open(argv, O_RDONLY);
	data_fill.s = get_next_line(data_fill.fd);
	while (fill.y_index < data[0][0].max_y)
	{
		data_fill.r = ft_split(data_fill.s, ' ');
		x_loop(fill, data, data_fill);
		fill.x_index = 0;
		fill.y_index++;
		free(data_fill.s);
		data_fill.s = get_next_line(data_fill.fd);
		data_fill.r = free_mem_splite(data_fill.r);
	}
	free(data_fill.s);
	data_fill.s = NULL;
	data_fill.r = free_mem_splite(data_fill.r);
	close(data_fill.fd);
}
