/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:56:51 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/06 09:09:48 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mem(struct s_points ***data)
{
	int	i;
	int	y;

	i = 0;
	y = data[0][0]->max_y;
	while (i < y)
	{
		free((*data)[i]);
		i++;
	}
	free(*data);
	*data = NULL;
}

void	data_manipulation(struct s_points **data, char *argv)
{
	fill_data(data, data[0][0].max_x, data[0][0].max_y, argv);
	iso_maker(data, data[0][0].max_x, data[0][0].max_y);
	change_data(data);
}

int	close_window(int keycode, struct s_combined *all_data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all_data->env->mlx, all_data->env->win);
		free_mem(all_data->data);
		if (all_data->env != NULL)
			if (all_data->env->img.img != NULL)
				mlx_destroy_image(all_data->env->mlx, all_data->env->img.img);
		free(all_data->env);
		exit(0);
	}
	return (0);
}

int	ft_x(struct s_combined *all_data)
{
	mlx_destroy_window(all_data->env->mlx, all_data->env->win);
	free_mem(all_data->data);
	if (all_data->env != NULL)
		if (all_data->env->img.img != NULL)
			mlx_destroy_image(all_data->env->mlx, all_data->env->img.img);
	free(all_data->env);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_points		**data;
	t_mlx				*env;
	struct s_combined	all_data;

	if (argc == 2)
	{
		map_check(argv[1]);
		allocate_data(&data, argv[1]);
		env = malloc(sizeof(t_mlx));
		data_manipulation(data, argv[1]);
		all_data.data = &data;
		all_data.env = env;
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, 1080, 1080, "fdf");
		env->img.img = mlx_new_image(&env->mlx, 1080, 1080);
		env->img.addr = mlx_get_data_addr(env->img.img,
				&env->img.bits_per_pixel, &env->img.line_length,
				&env->img.endian);
		draw(data, env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		mlx_hook(env->win, 2, 0, close_window, &all_data);
		mlx_hook(env->win, 17, 0, ft_x, &all_data);
		mlx_loop(env->mlx);
		return (0);
	}
}
