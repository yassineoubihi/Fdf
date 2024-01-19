/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/19 10:58:16 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_x_axes(void *mlx_ptr, void *win_ptr,struct points **data)
{
    int x;
    int y;
    int x_index;
    int y_index;

    x = 0;
    y = 0;
    x_index = 0;
    y_index = 0;
    count_rows_coluns(&x, &y);
    while(y_index < y)
    {
        while (x_index < x - 1)
        {
            if (data[y_index][x_index].z > 0)
                iso(&data[y_index][x_index].x,&data[y_index][x_index].y,data[y_index][x_index].z);
            drawline(mlx_ptr, win_ptr,data[y_index][x_index].x + 250,data[y_index][x_index].y + 250,data[y_index][x_index + 1].x + 250,data[y_index][x_index].y + 250);
            x_index++;
        }
        x_index = 0;
        y_index++;
    }
}

void draw_y_axes(void *mlx_ptr, void *win_ptr,struct points **data)
{
    int x;
    int y;
    int x_index;
    int y_index;

    x = 0;
    y = 0;
    x_index = 0;
    y_index = 0;
    count_rows_coluns(&x, &y);
    while(x_index < x)
    {
        while (y_index < y - 1)
        {
            if (data[y_index][x_index].z > 0)
                iso(&data[y_index][x_index].x,&data[y_index][x_index].y,data[y_index][x_index].z);
            drawline(mlx_ptr, win_ptr,data[y_index][x_index].x + 250,data[y_index][x_index].y + 250,data[y_index][x_index].x + 250,data[y_index + 1][x_index].y + 250);
            y_index++;
        }
        y_index = 0;
        x_index++;
    }
}

int main()
{
    void    *mlx_connection;
    void    *mlx_window;
    int y;
    int x;
    struct points **data;
    
    data = NULL;
    y = 0;
    x = 0;
    count_rows_coluns(&x,&y);
    allocate_data(&data, x, y);
    fill_data(data, x, y);
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection,1920,1080,"fdf");
    draw_x_axes(mlx_connection, mlx_window,data);
    draw_y_axes(mlx_connection, mlx_window,data);
    mlx_loop(mlx_connection);
    return (0);
}
