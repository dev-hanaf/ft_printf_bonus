/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/29 14:44:17 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_completion_of_minus_p(int width, int precision,
		unsigned long long num, int *count)
{
	int	len;

	len = counter_number_p(num);
	if (width > len && width > precision)
	{
		if (precision > len)
		{
			width -= precision;
			while (width-- > 0)
				*count += ft_putchar(' ');
		}
		else
		{
			width -= len;
			while (width-- > 0)
				*count += ft_putchar(' ');
		}
	}
}

int	ft_precision_of_minus_p(unsigned long long num, int precision, int width)
{
	int	len;
	int	count;
	int	tmp;
	int	tmp_num;

	count = 0;
	len = counter_number_p(num);
	tmp = precision;
	tmp_num = num;
	if (num == 0)
		precision--;
	if (precision > len)
	{
		while ((precision-- - len) > 0)
			count += ft_putchar('0');
	}
	count += ft_putaddresse(num);
	ft_completion_of_minus_p(width, tmp, tmp_num, &count);
	return (count);
}

void	ft_completion_of_regular_p(int len, int precision,
		unsigned long long num, int *count)
{
	if (precision > len)
	{
		while ((precision-- - len) > 0)
			*count += ft_putchar('0');
	}
	if (num != 0)
		*count += ft_putaddresse(num);
}

int	ft_precision_p(unsigned long long num, int precision, int width)
{
	int	len;
	int	count;

	len = counter_number_p(num);
	count = 0;
	if (width > precision && width > len)
	{
		if (precision)
		{
			width -= precision;
		}
		else
			width -= len;
		while (width--)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular_p(len, precision, num, &count);
	return (count);
}

// printf("%s\n",prs);
// printf(CYAN"width => %d\n"NC,width);
// printf(GREEN"precision => %d\n"NC,precision);

// puts("\n");

// printf(BLUE"%d",count_val_flags(flag));

// printf(RED"\n--------------------------------------------\n"NC);
// printf(CYAN"%s\n"NC,ft_parser(str, flag->start_indep, flag->end_indep));
// printf("\033[0;33mflag => precision %d\n", flag->precision);
// printf("flag => zero %d\n", flag->zero);
// printf("flag => minus %d\n", flag->minus);
// printf("flag => plus %d\n", flag->plus);
// printf("flag => space %d\n", flag->space);
// printf("flag => hash %d\n", flag->hash);
// printf("flag => start indep %d\n", flag->start_indep);
// printf("flag => end indep %d\033[0;0m\n", flag->end_indep);