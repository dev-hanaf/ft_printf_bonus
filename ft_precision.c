/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/03 20:14:59 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus(t_val *flag, int num, int *count)
{
	int	len;
	int	width;

	len = counter_number(num);
	width = 0;
	if (flag->width > flag->after_width && num < 0)
		flag->width--;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (num >= 0 && flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus(int num, t_val *flag)
{
	int	len;
	int	count;
	int	precision;
	int	tmp;

	precision = flag->after_width;
	tmp = num;
	count = 0;
	len = counter_number(tmp);
	if (tmp >= 0 && flag->plus)
		count += ft_putchar('+');
	if (tmp < 0)
	{
		count += ft_putchar('-');
		tmp *= -1;
	}
	if (precision > len)
	{
		while (precision-- - len > 0)
			count += ft_putchar('0');
	}
	if (tmp != 0)
		count += ft_putnbr(tmp);
	ft_completion_of_minus(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular(int len, t_val *flag, int num, int *count)
{
	int	precision;

	if (num >= 0 && flag->plus)
		*count += ft_putchar('+');
	if (num < 0)
	{
		*count += ft_putchar('-');
		num *= -1;
	}
	if (!flag->plus && flag->space)
		ft_print_space(num ,count, flag);
	if (flag->after_width > len)
	{
		precision = flag->after_width - len;
		while (precision-- > 0)
			*count += ft_putchar('0');
	}
	if (num != 0)
	{
		*count += ft_putnbr(num);
	}
}

int	ft_precision(int num, t_val *flag)
{
	int	len;
	int	count;
	int	width;

	len = counter_number(num);
	count = 0;
	width = 0;
	if (flag->width > flag->after_width && num < 0)
		flag->width--;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (num >= 0 && flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular(len, flag, num, &count);
	return (count);
}
