/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:14:00 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 01:38:03 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_minus(int num, int width)
{
    int count = 0;
    int len = counter_number(num);
    
    count += ft_putnbr(num);
    if (num < 0)
        width--;
    while (width - len > 0)
    {
        count += ft_putchar(' ');
        width--;
    }
    return (count);
}


