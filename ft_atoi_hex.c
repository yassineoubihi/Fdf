/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:31 by youbihi           #+#    #+#             */
/*   Updated: 2024/01/31 03:06:34 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int ft_atoi_hex(const char *hexaString)
{
    int length = strlen(hexaString);

    int startIndex = 0;
    if (length > 1 && hexaString[0] == '0' && (hexaString[1] == 'x' || hexaString[1] == 'X')) {
        startIndex = 2;
    }

    int decimalNumber = 0;

    for (int i = startIndex; i < length; ++i) {
        char currentChar = hexaString[i];
        int digitValue;

        if (currentChar >= '0' && currentChar <= '9') {
            digitValue = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            digitValue = currentChar - 'A' + 10;
        }
        else if (currentChar >= 'a' && currentChar <= 'f')
        {
            digitValue = currentChar - 'a' + 10;
        }
        else
        {
            printf("Invalid character in the hexadecimal string: %c\n", currentChar);
            return 0;
        }

        decimalNumber += digitValue * pow(16, length - i - 1);
    }

    return decimalNumber;
}