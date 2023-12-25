/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/25 01:59:00 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int ft_precision(int num, int precision, int width)
{
    int len = counter_number(num);
    int count = 0;
    if (width > (len + precision))
    {
        if (num < 0)
            width--;
        while (width-- - precision > 0u
            count += ft_putchar(' ');
    }
    if (num < 0)
    {
        ft_putchar('-');
        precision++;
        num *= -1;
    }
    if (precision > len)
    {
        while ((precision-- - len) > 0)
            count += ft_putchar('0');
    }
    count += ft_putnbr(num);
    return (count);
}


    // printf("%s\n",prs);
    // printf(CYAN"width => %d\n"NC,width);
    // printf(GREEN"precision => %d\n"NC,precision); 
    
    // puts("\n");

    // printf(BLUE"%d",count_val_flags(flag));
    
    // printf(RED"\n--------------------------------------------\n"NC);
    // printf(CYAN"%s\n"NC,ft_parser(str, flag->start_index, flag->end_index));
    // printf("\033[0;33mflag => precision %d\n", flag->precision);
    // printf("flag => zero %d\n", flag->zero);
    // printf("flag => minus %d\n", flag->minus);
    // printf("flag => plus %d\n", flag->plus);
    // printf("flag => space %d\n", flag->space);
    // printf("flag => hash %d\n", flag->hash);
    // printf("flag => start index %d\n", flag->start_index);
    // printf("flag => end index %d\033[0;0m\n", flag->end_index);