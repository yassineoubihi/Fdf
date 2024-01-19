/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:12:00 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/19 10:51:29 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void    dx_is_zero(void *mlx_ptr, void *win_ptr,struct algo args)
{
    int i;
    int step;

    i = 0;
    if (args.y1 > args.y0)
        step = 1;
    else
        step = -1;
    while (i < abs(args.dy))
    {
        args.y += step;
        mlx_pixel_put(mlx_ptr,win_ptr,args.x,args.y,0xffffff);
        i++;
    }
}
void    dx_not_zero(void *mlx_ptr,void *win_ptr,struct algo args)
{
    int i;

    i = 0;
    while (i < args.dx)
    {
        if (args.pk < 0)
        {
            mlx_pixel_put(mlx_ptr,win_ptr,args.x,args.y,0xffffff);
            args.pk += 2 * args.dy;
        }
        else
        {
            args.y++;
            mlx_pixel_put(mlx_ptr,win_ptr,args.x,args.y,0xffffff);
            args.pk += 2 * (args.dy - args.dx);
        }
        i++;
        args.x++;
    }
}

void drawline(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
    struct algo args;

    args.y1 = y1;
    args.y0 = y0;
    args.dx = abs(x1 - x0);
    args.dy = abs(y1 - y0);
    args.pk = 2 * args.dy - args.dx;
    args.x = x0;
    args.y = y0;
    mlx_pixel_put(mlx_ptr,win_ptr,args.x,args.y,0xffffff);
    if (args.dx == 0)
        dx_is_zero(mlx_ptr,win_ptr,args);
    else
        dx_not_zero(mlx_ptr,win_ptr,args);
}
