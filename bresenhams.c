/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:12:00 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/01 13:20:09 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(0.1) + *z * sin(0.1);
	*z = -previous_y * sin(0.1) + *z * cos(0.1);
}

/*
** Rotate coordinate by y axis
*/

void	rotate_y(int *x, int *z)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(0.1) + *z * sin(0.1);
	*z = -previous_x * sin(0.1) + *z * cos(0.1);
}

/*
** Rotate coordinate by z axis
*/

void	rotate_z(int *x, int *y)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(0.1) - previous_y * sin(0.1);
	*y = previous_x * sin(0.1) + previous_y * cos(0.1);
}

void change_data(struct points **data,char *argv)
{
    int x;
    int y;
    int x_index;
    int y_index;

    x = 0;
    y = 0;
    x_index = 0;
    y_index = 0;
    while (y_index < data[0][0].max_y)
    {
        while (x_index < data[0][0].max_x)
        {
            rotate_x(&data[y_index][x_index].y,&data[y_index][x_index].z);
            rotate_y(&data[y_index][x_index].x,&data[y_index][x_index].z);
            rotate_z(&data[y_index][x_index].x,&data[y_index][x_index].y);
            x_index++;
        }
        x_index = 0;
        y_index++;
    }
}

void iso(int *x, int *y, int z)
{
    int previous_x = *x;
    int previous_y = *y;

    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}
void iso_maker(struct points **data,int x, int y)
{
    int x_index;
    int y_index;

    x_index = 0;
    y_index = 0;
    while (y_index < y)
    {
        while (x_index < x)
        {
            iso(&data[y_index][x_index].x,&data[y_index][x_index].y,data[y_index][x_index].z);
            x_index++;
        }
        x_index = 0;
        y_index++;
    }
    x_index = 0;
    y_index = 0;
    while (y_index < y)
    {
        while (x_index < x)
        {
            data[y_index][x_index].x += 1080 / 2;
            data[y_index][x_index].y += 1080 / 2;
            x_index++;
        }
        x_index = 0;
        y_index++;
    }
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    if ( 0 < x && x < 1080 &&0 < y && y < 1080)
    {
	    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	    *(unsigned int*)dst = color;
    }
}

void drawline( int x0, int y0, int x1, int y1, int color, t_mlx *env)
{
    int dx = abs(x1 - x0);
   int sx = x0 < x1 ? 1 : -1;
   int dy = -abs(y1 - y0);
   int sy = y0 < y1 ? 1 : -1;
   int error = dx + dy;

   while (1) {
       my_mlx_pixel_put(&env->img, x0, y0, color);

       if (x0 == x1 && y0 == y1) {
           break;
       }

       int e2 = 2 * error;

       if (e2 >= dy) {
           if (x0 == x1) {
               break;
           }
           error = error + dy;
           x0 = x0 + sx;
       }

       if (e2 <= dx) {
           if (y0 == y1) {
               break;
           }
           error = error + dx;
           y0 = y0 + sy;
       }
   }

}
