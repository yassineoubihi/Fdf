/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:13:59 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/19 10:31:38 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void allocate_data(struct points ***data, int x, int y)
{
    int i;

    i = 0;
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
    data->x = x * 50;
    data->y = y * 50;
    data->z = ft_atoi(r[0]) * 50;
    data->color = ft_atoi_hex(r[1]);
}
void    no_color_habdel(struct points *data , char *s, int x, int y)
{
    data->x = x * 50;
    data->y = y * 50;
    data->z = ft_atoi(s) * 50;
    data->color = 16777215;
}

char    **handel_line()
{
    int fd;
    char **r;
    char *s;
    
    fd = open("test_maps/42.fdf",O_RDONLY);
    s = get_next_line(fd);
    r = ft_split(s, ' ');
    return (r);
}

void    fill_data(struct points **data, int x, int y)
{
    char    **s;
    int     x_index;
    int     y_index;

    x_index = 0;
    y_index = 0;
    while (y_index < y)
    {
        s = handel_line();
        while (x_index < x)
        {
            if (ft_custom_strchr(*s) == 1)
            {
                color_habdel(&data[y_index][x_index], *s,x_index,y_index);
            }
            else
            {
                no_color_habdel(&data[y_index][x_index], *s,x_index,y_index);
            }
            x_index++;
            s++;
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

void count_rows_coluns(int *x, int *y)
{
    char *s;
    int fd;
    int i;

    fd = open("test_maps/42.fdf",O_RDONLY);
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