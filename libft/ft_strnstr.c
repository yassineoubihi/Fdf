/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:18:25 by youbihi           #+#    #+#             */
/*   Updated: 2023/11/08 21:07:47 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	h;
	size_t	n;

	if (len == 0 && !str)
		return (NULL);
	h = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[h] != '\0')
	{
		n = 0;
		while (str[h + n] == to_find[n] && (h + n) < len)
		{
			if (str[h + n] == '\0' && to_find[n] == '\0')
				return ((char *)&str[h]);
			n++;
		}
		if (to_find[n] == '\0')
			return ((char *)str + h);
		h++;
	}
	return (0);
}
