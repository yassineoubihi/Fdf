/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/06 14:05:30 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int count_rows(char *s)
{
    int i;
    int r;
    char **result;

    result = ft_split(s,' ');
    i = 0;
    r = 0;
    while (result[i] != NULL)
    {
        r++;
        i++;
    }
    return (r);
}

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
void drawSteepLine(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = y1 - y0;
    int yStep = (y0 < y1) ? 1 : -1;

    // Check for positive or negative steep slope
    if (abs(dy) > dx) {
        // Ensure drawing starts from lower y to higher y
        if (y0 > y1) {
            swap(&x0, &x1);
            swap(&y0, &y1);
            dy = -dy;
        }

        int x = x0;
        int error = 2 * dx - dy;

        for (int y = y0; y <= y1; y++) {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);

            if (error > 0) {
                x += (dy > 0) ? 1 : -1; // Increment x for positive slope, decrement for negative
                error -= 2 * dy;
            }
            error += 2 * dx;
        }
    }
}

void count_rows_coluns(int *c, int *r)
{
    char *s;
    int fd;
    int i;

    fd = open("test_maps/pyra.fdf",O_RDONLY);
    i = 0;
    s = get_next_line(fd);
    while (s != NULL)
    {
        *r = count_rows(s);
        i++;
        (*c)++;
        free(s);
        s = get_next_line(fd);
        
    }
    free(s);
    s = NULL;
}
void draw_x_axes(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
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
        x0 = 0;
        while (coluns_index < coluns)
        {
            x1 += 10;
            drawline(mlx_ptr, win_ptr,x0,y0,x1,y1);
            // printf("(x0 = %d, y0 = %d),(x1 = %d, y1 = %d)\n",x0,y0,x1,y1);
            coluns_index++;
        }
        rows_index++;
        y1 = y0 += 10;
        x1 = 0;
        coluns_index=0;
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
    while(coluns_index < coluns + 1)
    {
        y0 = 0;
        while (rows_index < rows)
        {
            y1 += 10;
            drawSteepLine(mlx_ptr, win_ptr,x0,y0,x1,y1);
            printf("(x0 = %d, y0 = %d),(x1 = %d, y1 = %d)\n",x0,y0,x1,y1);
            rows_index++;
        }
        rows_index = 0;
        x1 = x0 += 10;
        y1 = 0;
        coluns_index++;
    } 
} 
int main()
{
    int     coluns;
    int     rows;
    void    *mlx_connection;
    void    *mlx_window;
    int     rows_index;
    int     coluns_index;
    int     x0;
    int     y0;
    int     x1;
    int     y1;

    coluns = 0;
    x0 = 0;
    y0 = 0;
    x1 = 0;
    y1 = 0;
    rows = 0;
    rows_index = 0;
    coluns_index = 0;
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection,1000,1000,"fdf");
    draw_x_axes(mlx_connection, mlx_window,x0,y0,x1,y1);
    printf("\n\n\n\n\n");
    draw_y_axes(mlx_connection, mlx_window,x0,y0,x1,y1);
    
    mlx_loop(mlx_connection);
    return 0;
}
