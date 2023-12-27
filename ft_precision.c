/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/27 05:22:17 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_precision2(int num, int precision, int width) {
    int len;
    int count = 0;
    int tmp;

    len = counter_number(num);

    if (num < 0) {
        ft_putchar('-');
        precision++;
        num *= -1;
    }
    tmp = precision;

	if (num == 0)
		precision--;


    if (precision > len) {
        while ((precision-- - len) > 0)
            count += ft_putchar('0');
    }

    count += ft_putnbr(num);


    if (width > len && width > tmp) {
		if (tmp)
			width -= tmp;
		else
			width -= len;
        while (width-- > 0)
            count += ft_putchar(' ');
    }

	return (count);
}

int	ft_precision(int num, int precision, int width)
{
	int	len;
	int	count;

	len = counter_number(num);
	count = 0;
	if (width > precision && width > len)
	{
		if (precision)
		{
			width -= precision;
			if (num < 0)
				width--;	
		}
		else
			width -= len;
		while(width--)
			count += ft_putchar(' ');
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		precision++;
		num *= -1;
	}
	if (precision > len)
	{
		while ((precision-- - len) > 0)
			count += ft_putchar('0');
	}
	if (num != 0)
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