/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:32:04 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 05:11:42 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// add zeros * width - len 
int ft_zero(int num, int width)
{
    int count;
    int len;

    len = counter_number(num);
    count = 0;
    if (num < 0)
    {
        count += ft_putchar('-');
        num *= -1;
    }
    while (width-- - len > 0)
        count += ft_putchar('0');
    count += ft_putnbr(num);   
    return (count);
}