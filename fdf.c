/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/03 02:40:39 by youbihi          ###   ########.fr       */
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



int main()
{
    char **lines = NULL;
    void *mlx_ptr;
    void *win_ptr;
    int i, c , index;
    int fd;
    int x0, y0, x1, y1;

    lines = malloc(3 * sizeof(char *));
    i = c = index = 0;
    x0 = y0 = x1 = y1 = 0;
    fd = open("map.txt",O_RDONLY);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
    *lines = get_next_line(fd);
    while (1)
    {
        int j = 0;
        char **result;
        
        result = ft_split(lines[i], ' ');
        while (result && result[j])
        {
            if (result[c] && result[c][0] == 48)
            {
                drawLine(mlx_ptr,win_ptr, x0, y0, x1, y1);
                c++;
                x1 += 100;
            }
            else if(result[c] && result[c][0] == 49)
            {
                drawLine(mlx_ptr,win_ptr, x0, y0, x1, y1 - 100);
                c++;
                x1 += 100;
            }
            j++;
        }
        y1 += 100;
        i++;
        *(lines + i) = get_next_line(fd);
        if (*(lines + i) == NULL)
            break;
    }
    mlx_loop(mlx_ptr);

    return 0;
}
