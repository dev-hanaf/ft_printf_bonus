/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:32:04 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/03 14:39:33 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_zero(int num, int width)
{
	int	count;
	int	len;

	len = counter_number(num);
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		width--;
		num *= -1;
	}
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_putnbr(num);
	return (count);
}

int	ft_zero_u(unsigned int num, int width)
{
	int	count;
	int	len;

	len = counter_number_u(num);
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_putnbr_u(num);
	return (count);
}

int	ft_zero_x(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	len = counter_number_x(num, flag);
	if (num == 0)
		width--;
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_puthexa(num, 'x');
	return (count);
}

int	ft_zero_X(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	len = counter_number_x(num, flag);
	if (num == 0)
		width--;
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_puthexa(num, 'X');
	return (count);
}

int	ft_zero_p(unsigned long long num, int width)
{
	int	count;
	int	len;

	len = counter_number_p(num);
	if (num == 0)
		width--;
	count = 0;
	count += ft_putstr("0x");
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_putaddresse(num);
	return (count);
}
