/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/09 05:29:59 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_x_axes(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
    //  ||||||
    int coluns;
    //  -------
    int rows;
    int coluns_index;
    int rows_index;

    coluns = 0;
    rows = 0;
    coluns_index = 0;
    rows_index = 0;
    count_rows_coluns(&coluns, &rows);
    while(coluns_index <= coluns )
    {
        x0 = 0;
        while (rows_index < rows)
        {
            x1 += 10;
            drawline(mlx_ptr, win_ptr,x0,y0,x1,y1);
            rows_index++;
        }
        coluns_index++;
        y1 = y0 += 10;
        x1 = 0;
        rows_index=0;
    }
}

void draw_y_axes(void *mlx_ptr, void *win_ptr,int x0, int y0, int x1, int y1)
{  
    int coluns;
    int rows;
    int coluns_index;
    int rows_index;

    coluns = 0;
    rows = 0;
    coluns_index = 0;
    rows_index = 0;
    count_rows_coluns(&coluns, &rows);
    while(rows_index <= rows)
    {
        y0 = 0;
        while (coluns_index < coluns)
        {
            y1 += 10;
            drawSteepLine(mlx_ptr, win_ptr,x0,y0,x1,y1);
            coluns_index++;
        }
        coluns_index = y1 = 0;
        x1 = x0 += 10;
        rows_index++;
    } 
}

int main()
{
    void    *mlx_connection;
    void    *mlx_window;
    Node my_data;

    my_data.x0 = 0;
    my_data.x1 = 0;
    my_data.y0 = 0;
    my_data.y0 = 0;
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection,1000,1000,"fdf");
    draw_x_axes(mlx_connection, mlx_window,my_data.x0,my_data.y0,my_data.x1,my_data.y1);
    draw_y_axes(mlx_connection, mlx_window,my_data.x0,my_data.y0,my_data.x1,my_data.y1);
    mlx_loop(mlx_connection);
    return (0);
}
