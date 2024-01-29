/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:05:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/30 00:27:35 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    zed_high_helper(struct draw_param param,struct points **data,t_mlx *env)
{

    drawline(data[param.y][param.x].x,data[param.y][param.x].y,data[param.y ][param.x + 1].x,data[param.y][param.x + 1].y,0xffffff,env);
    drawline(data[param.y][param.x].x,data[param.y][param.x].y,data[param.y + 1][param.x].x,data[param.y + 1][param.x].y,0xffffff,env);
}
void    zed_high_helper_second(struct draw_param param,struct points **data,t_mlx *env)
{
    if (param.x < data[0][0].max_x - 1)
    {
        if (param.x > 0)
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y][param.x + 1].x,data[param.y][param.x + 1].y,0xffffff,env);
        else
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y][param.x + 1].x,data[param.y][param.x + 1].y,0xffffff,env);
    }
    if (param.y < data[0][0].max_y - 1)
    {
        if (param.y > 0)
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y + 1][param.x].x,data[param.y + 1][param.x].y,0xffffff,env);
        else
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y + 1][param.x].x,data[param.y + 1][param.x].y,0xffffff,env);
    }
}


void    zed_high(struct draw_param param,struct points **data,t_mlx *env)
{
    if ((param.x < data[0][0].max_x - 1) && (param.y < data[0][0].max_y - 1))
    {
        zed_high_helper(param,data,env);
    }
    else
    {
        zed_high_helper_second(param,data,env);
    }
}

void    zed_low(struct draw_param param,struct points **data,t_mlx *env)
{
    if ((param.x < data[0][0].max_x - 1) && (param.y < data[0][0].max_y - 1))
    {
        drawline(data[param.y][param.x].x,data[param.y][param.x].y
            ,data[param.y ][param.x + 1].x,data[param.y][param.x + 1].y,0xffff00,env);
        drawline(data[param.y][param.x].x,data[param.y][param.x].y
            ,data[param.y + 1][param.x].x,data[param.y + 1][param.x].y,0xffff00,env);
    }
    else
    {
        if (param.x < data[0][0].max_x - 1)
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y][param.x + 1].x,data[param.y][param.x + 1].y,0xffff00,env);
        if (param.y < data[0][0].max_y - 1)
            drawline(data[param.y][param.x].x,data[param.y][param.x].y
                ,data[param.y + 1][param.x].x,data[param.y + 1][param.x].y,0xffff00,env);
    }
}

void draw(struct points **data,char *argv,t_mlx *env)
{
    struct draw_param param;
    param.x = 0;
    param.y = 0;
    while (param.y < data[0][0].max_y)
    {
        while (param.x < data[0][0].max_x)
        {
            if (data[param.y][param.x].z > 0 || data[param.y][param.x].z < 0)
                zed_high(param,data,env);
            else
                zed_low(param,data,env);
            param.x++;
        }
        param.x = 0;
        param.y++;
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
        allocate_data(&data,argv[1]);
        fill_data(data, data[0][0].max_x, data[0][0].max_y,argv[1]);
        iso_maker(data,data[0][0].max_x,data[0][0].max_y);
        // change_data(data,argv[1]);
        env->mlx = mlx_init();
        env->win = mlx_new_window(env->mlx,1080,1080,"fdf");
        env->img.img = mlx_new_image(&env->mlx, 1080, 1080);
        env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
        draw(data,argv[1],env);
        mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
        mlx_loop(env->mlx);
        return (0);
    }
}
