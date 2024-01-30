/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:01:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/30 02:40:26 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

static char	**free_mem(char **tab)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static char	*words_len(const char *s, char c, size_t *w)
{
	char		*word;
	size_t		len;
	size_t		i;
	size_t		j;

	len = 0;
	j = 0;
	while (s[*w] && s[*w] == c)
		(*w)++;
	i = *w;
	while (s[*w] && s[*w] != c)
		(*w)++;
	len = *w - i;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i + j < *w)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	word;
	char	**str;
	size_t	w;
	size_t	id;

	if (!s)
		return (NULL);
	word = ft_countword(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	w = 0;
	id = 0;
	while (w < word)
	{
		str[w] = words_len(s, c, &id);
		if (!str[w])
			return (free_mem(str));
		w++;
	}
	str[word] = NULL;
	return (str);
}
