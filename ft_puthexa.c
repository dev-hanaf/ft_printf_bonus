/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 05:10:23 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/29 06:57:24 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_puthexa(unsigned int num, char f)
{
    static int count = 0;

    if (num >= 16)
    {
        ft_puthexa(num / 16, f);
        num = num % 16;
    }      
    if (f == 'x')
        count += ft_putchar("0123456789abcdef"[num]);
    else if (f == 'X')
        count += ft_putchar("0123456789ABCDEF"[num]);
    
    return (count);
}
