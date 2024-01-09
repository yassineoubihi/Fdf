/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:13:59 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/09 05:30:01 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
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

void count_rows_coluns(int *c, int *r)
{
    char *s;
    int fd;
    int i;

    fd = open("test_maps/42.fdf",O_RDONLY);
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
    close(fd);
    s = NULL;
}