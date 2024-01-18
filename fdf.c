/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/18 18:36:00 by youbihi          ###   ########.fr       */
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
    // printf("\n\ncolums = %d || rows = %d\n\n",coluns,rows);
    // printf("c = %d || r = %d",coluns,rows);
    while(y_index < y)
    {
        while (x_index < x - 1)
        {
            // puts("here");
            drawline(mlx_ptr, win_ptr,data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index + 1].x + 100,data[y_index][x_index].y + 100);
            // printf("x0 = %d // y0 = %d // x1 = %d // y1 = %d\n",data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index + 1].x  + 100,data[y_index][x_index + 1].y  + 100);
            // printf("y0 = %d || y1 = %d\n",data[y_index][x_index].y + 100, data[y_index][x_index + 1].y + 100);
            // printf("\nx = %d\n",data[coluns_index][rows_index].x);
            x_index++;
            // if ((data[y_index][x_index + 1].x * 10 + 100) == 200)
            //     data[y_index][x_index + 1].x  = 100 ;
        }
        x_index = 0;
        // printf("\n================================================================================\n");
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
    // printf("\n\ncolums = %d || rows = %d\n\n",coluns,rows);
    // printf("c = %d || r = %d",coluns,rows);
    while(x_index < x)
    {
        while (y_index < y - 1)
        {
            // puts("here");
            drawline(mlx_ptr, win_ptr,data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index].x + 100,data[y_index + 1][x_index].y + 100);
            // printf("x0 = %d // y0 = %d // x1 = %d // y1 = %d\n",data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index].x + 100,data[y_index][x_index + 1].y + 100);
            // printf("y0 = %d || y1 = %d\n",data[x_index][y_index].y + 100, data[x_index][y_index + 1].y + 100);
            printf("x = %d || y = %d\n",x_index,y_index);
            // printf("\nx = %d\n",data[coluns_index][rows_index].x);
            y_index++;
            // if ((data[y_index][x_index + 1].x * 10 + 100) == 200)
            //     data[y_index][x_index + 1].x  = 100 ;
        }
        y_index = 0;
        printf("\n================================================================================\n");
        x_index++;
    }
}

// void draw_y_axes(void *mlx_ptr, void *win_ptr,struct points **data)
// {  
//     int x;
//     int y;
//     int x_index;
//     int y_index;

//     x = 0;
//     y = 0;
//     x_index = 0;
//     y_index = 0;
//     count_rows_coluns(&x, &y);
//     // printf("\n\ncolums = %d || rows = %d\n\n",coluns,rows);
//     // printf("c = %d || r = %d",coluns,rows);
//     while(x_index < x)
//     {
//         while (y_index < y)
//         {
//             // puts("here");
//             drawline(mlx_ptr, win_ptr,data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index].x + 100,data[y_index][x_index + 1].y + 100);
//             // printf("x0 = %d // y0 = %d // x1 = %d // y1 = %d\n",data[y_index][x_index].x + 100,data[y_index][x_index].y + 100,data[y_index][x_index + 1].x  + 100,data[y_index][x_index + 1].y  + 100);
//             // printf("y0 = %d || y1 = %d\n",data[y_index][x_index].y + 100, data[y_index][x_index + 1].y + 100);
//             // printf("\nx = %d\n",data[coluns_index][rows_index].x);
//             y_index++;
//             // if ((data[y_index][x_index + 1].x * 10 + 100) == 200)
//             //     data[y_index][x_index + 1].x  = 100 ;
//         }
//         y_index = 0;
//         // printf("\n================================================================================\n");
//         x_index++;
//     }
// }

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
    // int i, b;

    // i = b = 0;
    // while (b < y)
    // {
    //     while (i < x)
    //     {
    //         printf("x = %d || y = %d || z = %d\n",data[b][i].x,data[b][i].y,data[b][i].z);
    //         i++;
    //     }
    //     printf("\n===========================================\n");
    //     i = 0;
    //     b++;
    // }
    // printf("\ny = %d  x = %d\n",column,row);
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection,1500,1000,"fdf");
    draw_x_axes(mlx_connection, mlx_window,data);
    // printf("\n\n===================================================================\n\n");
    draw_y_axes(mlx_connection, mlx_window,data);
    mlx_loop(mlx_connection);
    return (0);
}
