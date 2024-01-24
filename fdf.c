/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/24 14:14:59 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw(struct points **data,char *argv,t_mlx *env)
{
    int x_index;
    int y_index;
    int x,y;
    
    x_index = 0;
    y_index = 0;
    x = 0;
    y = 0;
    count_rows_coluns(&x,&y,argv);
    while (y_index < y)
    {
        x_index = 0;
        while (x_index < x)
        {
            if (data[y_index][x_index].z > 0)
            {
                if ((x_index < x - 1) && (y_index < y - 1))
                {
                    if (y_index > 0 && x_index > 0)
                    {
                        drawline(data[y_index][x_index - 1].x + 480,data[y_index][x_index - 1].y + 270,data[y_index ][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffffff,env);
                        drawline(data[y_index - 1][x_index].x + 480,data[y_index - 1][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffffff,env);
                    }
                    else
                    {
                        drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index ][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffffff,env);
                        drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffffff,env);
                    }
                }
                else
                {
                    if (x_index < x - 1)
                    {
                        if (x_index > 0)
                            drawline(data[y_index][x_index - 1].x + 480,data[y_index][x_index - 1].y + 270,data[y_index][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffffff,env);
                        else
                            drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffffff,env);
                    }
                    if (y_index < y - 1)
                    {
                        if (y_index > 0)
                            drawline(data[y_index - 1][x_index].x + 480,data[y_index - 1][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffffff,env);
                        else
                            drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffffff,env);
                    }
                }
            }
            else
            {
                if ((x_index < x - 1) && (y_index < y - 1))
            {
                drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index ][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffff00,env);
                drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffff00,env);
            }
            else
            {
                if (x_index < x - 1)
                    drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index][x_index + 1].x + 480,data[y_index][x_index + 1].y + 270,0xffff00,env);
                if (y_index < y - 1)
                    drawline(data[y_index][x_index].x + 480,data[y_index][x_index].y + 270,data[y_index + 1][x_index].x + 480,data[y_index + 1][x_index].y + 270,0xffff00,env);
            }
            }
            x_index++;
        }
        y_index++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int y;
        int x;
        struct points **data;
        t_mlx *env;
    
        data = NULL;
        y = 0;
        x = 0;
        env = malloc(sizeof(t_mlx));
        count_rows_coluns(&x,&y,argv[1]);
        allocate_data(&data, x, y);
        fill_data(data, x, y,argv[1]);
        iso_maker(data,x,y);
        change_data(data,argv[1]);
        env->mlx = mlx_init();
        env->win = mlx_new_window(env->mlx,1920,1080,"fdf");
        env->img.img = mlx_new_image(&env->mlx, 1920, 1080);
        env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
        draw(data,argv[1],env);
        mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
        mlx_loop(env->mlx);
        return (0);
    }
}
