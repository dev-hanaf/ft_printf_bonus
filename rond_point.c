/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 02:08:47 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int add_spaces(int num,int width)
{
    int count = 0;
    int len = counter_number(num);
    
    if (num < 0)
    {
        width--;
        num *= -1;
    }
    while (width-- -len > 0)
        count += ft_putchar(' ');
    return (count);
}
int rond_point(t_val *flag, const char *str, int num)
{
    flag->start_index = flag->end_index  - count_val_flags(flag);
    char *prs = ft_parser(str, flag->start_index, flag->end_index);
    // printf(CYAN"%s\n"NC,prs);

    // int i = 0;
    int count = 0;
    int width = ft_width(prs);
    // printf(RED"%d\n"NC,width);
    int precision = 0;


    if (flag->minus && width && !flag->precision)
        count += ft_minus(num,width);
    else if (flag->minus && width && flag->precision)
    {
        precision = ft_get_precision(prs);
        count += ft_precision2(num, precision,width);
    }
    else if (flag->precision)
    {
        precision = ft_get_precision(prs);
        count += ft_precision(num, precision,width);
    }
    else if (width && !flag->precision)
    {
        count += add_spaces(num, width);
        count += ft_putnbr(num);
    }
    else if (count_val_flags(flag) == 0 && !width)
        count += ft_putnbr(num);
    free(prs);
    return (count);    
}
