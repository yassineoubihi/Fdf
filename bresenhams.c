/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:12:00 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/09 05:30:03 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawline(void *mlx_ptr, void *win_ptr,int x0, int y0, int x1, int y1)
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {  
           mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {  
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
            p=p+2*dy;}  
            x=x+1;  
        }  
}
void drawSteepLine(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
    int dx;
    int dy;
    int yStep;
    int x;
    int error;

    dx = abs(x1 - x0);
    dy = y1 - y0;
    yStep = (y0 < y1) ? 1 : -1;
    if (abs(dy) > dx) 
    {
        if (y0 > y1)
        {
            swap(&x0, &x1);
            swap(&y0, &y1);
            dy = -dy;
        }
        x = x0;
        error = 2 * dx - dy;
        for (int y = y0; y <= y1; y++)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
            if (error > 0)
            {
                x += (dy > 0) ? 1 : -1;
                error -= 2 * dy;
            }
            error += 2 * dx;
        }
    }
}