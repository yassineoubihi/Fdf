/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:31 by youbihi           #+#    #+#             */
/*   Updated: 2023/11/10 20:11:46 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	b;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	b = 0;
	while (b < i)
	{
		str[b] = f(b, s[b]);
		b++;
	}
	str[b] = '\0';
	return (str);
}
