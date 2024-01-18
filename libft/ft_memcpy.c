/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:01:39 by youbihi           #+#    #+#             */
/*   Updated: 2023/11/05 22:03:00 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	if (!source && !destination)
		return (0);
	if (num == 0)
		return (destination);
	i = 0;
	while (i < num)
	{
		*(char *)destination = *(char *)source;
		i++;
		destination++;
		source++;
	}
	return (destination - i);
}
