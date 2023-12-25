/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:03:03 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 00:17:07 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_get_precision(char *prs)
{
    int precision = 0;
    int i = 0;
    
    while (prs[i] != '.')
        i++;
    i++; 
    while (prs[i])
    {
        if (ft_isdigit(prs[i]))
            precision = precision * 10 + (prs[i] - '0');
        i++;
    }
    return (precision);
}
