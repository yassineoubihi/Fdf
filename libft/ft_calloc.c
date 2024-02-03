/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:48:30 by youbihi           #+#    #+#             */
/*   Updated: 2023/11/05 17:54:54 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	while (i < size * nmemb)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
