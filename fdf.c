/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/06 06:53:48 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

void drawLine(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x < x1) {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
        if (p >= 0) {
            y++;
            p += 2 * dy - 2 * dx;
        } else {
            p += 2 * dy;
        }
        x++;
    }
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

void count_rows_coluns(int *c, int *r)
{
    char *s;
    int fd;
    int i;

    fd = open("map.txt",O_RDONLY);
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
    count_rows_coluns(&coluns, &rows);
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection,1000,1000,"fdf");
    while(coluns_index < coluns)
    {
        x0 = 0;
        while (rows_index < rows)
        {
            x1 += 100;
            drawLine(mlx_connection, mlx_window,x0,y0,x1,y1);
            printf("(x0 = %d, y0 = %d),(x1 = %d, y1 = %d)\n",x0,y0,x1,y1);
            rows_index++;
            x0 += 100;
        }
        rows_index = 0;
        x1 = 0;
        y0 += 100;
        y1 = 0;
        coluns_index++;
    }
    mlx_loop(mlx_connection);
    return 0;
}
