/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:12:00 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/18 18:33:38 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawline(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int pk = 2 * dy - dx;
    int x = x0, y = y0;
    mlx_pixel_put(mlx_ptr,win_ptr,x,y,0xffffff);

    if (dx == 0) {  // Vertical line
        int step = (y1 > y0) ? 1 : -1;
        for (int i = 0; i < abs(dy); i++) {
            y += step;
            mlx_pixel_put(mlx_ptr,win_ptr,x,y,0xffffff);
        }
    } else {
        for (int i = 0; i < dx; i++) {
            if (pk < 0) {
                mlx_pixel_put(mlx_ptr,win_ptr,x,y,0xffffff);
                pk += 2 * dy;
            } else {
                y++;
                mlx_pixel_put(mlx_ptr,win_ptr,x,y,0xffffff);
                pk += 2 * (dy - dx);
            }
            x++;
        }
    }
}
