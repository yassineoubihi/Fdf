/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:13:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/05 18:12:09 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

static int	func_atoi(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f');
}

static int	func_atoi_0(const char *s, int i, int neg)
{
	unsigned long long	res;
	int					digitnbr;

	res = 0;
	digitnbr = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		digitnbr++;
		if (digitnbr == 20)
		{
			if (neg == -1)
				return (0);
			else
				return (-1);
		}
		res = (res * 10) + (s[i++] - '0');
	}
	if (res > LONG_MAX)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	return (((int)res) * neg);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || func_atoi(s[i])))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] && s[i] == '0')
		i++;
	return (func_atoi_0(s, i, neg));
}
