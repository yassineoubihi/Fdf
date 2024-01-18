/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:31 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/15 14:10:14 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_atoi_hex(const char *s)
{
    int i;
    int neg;

    i = 0;
    neg = 1;
    while (s[i] && (s[i] == ' ' || func(s[i])))
        i++;
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
        i += 2;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            neg *= -1;
        i++;
    }
    while (s[i] && s[i] == '0')
        i++;
    return func0(s, i, neg);
}