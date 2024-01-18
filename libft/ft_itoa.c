/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:18:35 by youbihi           #+#    #+#             */
/*   Updated: 2023/11/07 16:32:49 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*str;
	long int			len;
	unsigned int		nb;
	int					sign;
	long				number;

	number = n;
	sign = 1;
	len = ft_len(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		sign *= -1;
		nb = number * -1;
		str[0] = '-';
	}
	else
		nb = number;
	str = ft_char(str, nb, len);
	return (str);
}
/*
int main(void)
{
	printf("%s\n",ft_itoa(2147483648));
	//printf("%s",itoa(2147483647));
	return (0);
}
*/