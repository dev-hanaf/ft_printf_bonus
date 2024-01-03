/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/03 13:33:15 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_completion_of_minus_X(t_val *flag, unsigned int num, int *count)
{
	int	len;
	int	width;

	len = counter_number_x(num, flag);
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus_X(unsigned int num, t_val *flag)
{
	int				len;
	int				count;
	int				precision;
	unsigned int	tmp;

	precision = flag->after_width;
	tmp = num;
	count = 0;
	len = counter_number_x(tmp, flag);
	if (flag->hash && num != 0)
	{
		count += ft_putstr("0X");
		flag->after_width += 2;
	}
	if (precision > len)
	{
		while (precision-- - len > 0)
		{
			count += ft_putchar('0');
		}
	}
	if (tmp != 0)
		count += ft_puthexa(tmp, 'X');
	ft_completion_of_minus_X(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular_X(int len, t_val *flag, unsigned int num,
		int *count)
{
	int	precision;

	if (flag->hash && num != 0)
	{
		*count += ft_putstr("0X");
		flag->after_width += 2;
	}
	if (flag->after_width > len)
	{
		precision = flag->after_width - len;
		while (precision-- > 0)
			*count += ft_putchar('0');
	}
	if (num != 0)
	{
		*count += ft_puthexa(num, 'X');
	}
}

int	ft_precision_X(unsigned int num, t_val *flag)
{
	int	len;
	int	count;
	int	width;

	len = counter_number_x(num, flag);
	count = 0;
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular_X(len, flag, num, &count);
	return (count);
}
