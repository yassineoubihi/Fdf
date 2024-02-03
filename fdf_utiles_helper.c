/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utiles_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:43:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/03 02:52:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_calcul(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

void	allocate_data(struct s_points ***data, char *argv)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	x = 0;
	count_rows_coluns(&x, &y, argv);
	*data = malloc(y * sizeof(struct s_points *));
	if (*data == NULL)
		exit(1);
	while (i < y)
	{
		(*data)[i] = malloc(x * sizeof(struct s_points));
		if ((*data)[i] == NULL)
			exit(1);
		i++;
	}
	data[0][0]->max_x = x;
	data[0][0]->max_y = y;
}

int	ishexdigit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'
			&& c <= 'F'));
}

int	ft_custom_strchr(char *s)
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
