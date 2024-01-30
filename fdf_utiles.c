/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:13:59 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/30 07:46:51 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int min_calcul(int x, int y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

int calculate_space(int x)
{
    int len;
    int r;

    len = 750-250;
    r = len / x;
    return (r);
}

void allocate_data(struct points ***data, char *argv)
{
    int i;
    int x;
    int y;

    i = 0;
    count_rows_coluns(&x,&y,argv);
    *data = malloc(y * sizeof(struct points *));
    if (*data == NULL)
        exit(1);
    while(i < y)
    {
        (*data)[i] = malloc(x * sizeof(struct points));
        if ((*data)[i] == NULL)
            exit(1);
        i++;
    }
    data[0][0]->max_x = x;
    data[0][0]->max_y = y;
}

int isHexDigit(char c)
{
    return ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F'));
}

int ft_custom_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
    {
        if (s[i] == ',')
        {
            return (1);
        }
        i++;
    }
	return (0);
}

void    color_habdel(struct points *data , char *s, int x, int y)
{
    char    **r;

    r = ft_split(s, ',');
    data->screen_x = 1080;
    data->screen_y = 1080 ;
    data->the_min = min_calcul((data->screen_x / data->max_x/ 2),(data->screen_y / data->max_y / 2));
    data->x = x  * data->the_min;
    data->y = y  * data->the_min;
    data->z = ft_atoi(r[0]) * data->the_min;
    if (r[1] != NULL)
        data->color = ft_atoi_hex(r[1]);
    else
        data->color = 16777215;
}
void    no_color_habdel(struct points *data , char *s, int x, int y)
{
    data->screen_x = 1080;
    data->screen_y = 1080;
    data->the_min = min_calcul((data->screen_x / data->max_x/ 2),(data->screen_y / data->max_y / 2));
    data->x = x  * data->the_min;
    data->y = y  * data->the_min;
    data->z = ft_atoi(s) * data->the_min;
    data->color = 16777215;
}

char    **handel_line(char *argv,int x)
{
    int fd;
    char **r;
    char *s;

    fd = open(argv,O_RDONLY);
    s = get_next_line(fd);
    r = ft_split(s, ' ');
    return (r);
}

void    fill_data(struct points **data, int x, int y, char *argv)
{
    char    **s;
    int     x_index;
    int     y_index;

    x_index = 0;
    y_index = 0;
    while (y_index < data[0][0].max_y)
    {
        s = handel_line(argv,data[0][0].max_x);
        while (x_index < data[0][0].max_x)
        {
            data[y_index][x_index].max_x = x;
            data[y_index][x_index].max_y = y;
            if (s != NULL && s[x_index] != NULL && s[x_index + 1] != NULL && ft_custom_strchr(s[x_index]) == 1)
                color_habdel(&data[y_index][x_index], s[x_index],x_index,y_index);
            else if (s != NULL && s[x_index] != NULL)
                no_color_habdel(&data[y_index][x_index], s[x_index],x_index,y_index);
            x_index++;
        }
        x_index = 0;
        s++;
        y_index++;
    }
}


void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int count_x_rows(char *s)
{
    int i;
    int x;
    char **result;

    result = ft_split(s,' ');
    i = 0;
    x = 0;
    while (result[i] != NULL)
    {
        x++;
        i++;
    }
    return (x);
}

void count_rows_coluns(int *x, int *y,char *argv)
{
    char *s;
    int fd;
    int i;

    fd = open(argv,O_RDONLY);
    i = 0;
    s = get_next_line(fd);
    while (s != NULL)
    {
        *x = count_x_rows(s);
        i++;
        (*y)++;
        free(s);
        s = get_next_line(fd);
    }
    free(s);
    close(fd);
    s = NULL;
}