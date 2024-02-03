/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:27:03 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/09 05:30:04 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen_g(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_line_len(char *str)
{
	int	i;
	int	back_slash_zero_count;

	i = 0;
	back_slash_zero_count = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			back_slash_zero_count++;
		i++;
	}
	return (i - back_slash_zero_count);
}

int	count_len_for_left(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i] != '\n')
		i++;
	while (str[i + index])
		index++;
	return (index);
}

char	*ft_left_lines(char *all_lines)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (all_lines[i] && all_lines[i] != '\n')
		i++;
	if (!all_lines[i])
	{
		free(all_lines);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_g(all_lines) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (all_lines[i])
		temp[j++] = all_lines[i++];
	temp[j] = '\0';
	free(all_lines);
	return (temp);
}

char	*ft_strjoin_g(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_g(left_str) + ft_strlen_g(buff))
				+ 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_g(left_str) + ft_strlen_g(buff)] = '\0';
	free(left_str);
	return (str);
}
