/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:56:51 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/03 00:41:44 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	struct s_points	**data;
	t_mlx			*env;

	if (argc == 2)
	{
		data = NULL;
		env = malloc(sizeof(t_mlx));
		allocate_data(&data, argv[1]);
		fill_data(data, data[0][0].max_x, data[0][0].max_y, argv[1]);
		iso_maker(data, data[0][0].max_x, data[0][0].max_y);
		change_data(data, argv[1]);
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, 1080, 1080, "fdf");
		env->img.img = mlx_new_image(&env->mlx, 1080, 1080);
		env->img.addr = mlx_get_data_addr(env->img.img,
				&env->img.bits_per_pixel, &env->img.line_length,
				&env->img.endian);
		draw(data, argv[1], env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		mlx_loop(env->mlx);
		return (0);
	}
}
