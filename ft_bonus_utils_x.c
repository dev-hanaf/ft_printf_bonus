/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:50 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/02 20:27:52 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces_x(unsigned int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_x(num);
	if (num == 0)
		width--;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

void	ft_print_plus_x(unsigned int num, int *count, t_val *flag)
{
	if (flag->plus)
	{
		flag->width--;
		*count += add_spaces_x(num, flag->width);
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_plus_minus_x(int *count, t_val *flag)
{
	if (flag->plus)
	{
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_space_x(int *count, t_val *flag)
{
	if (flag->space && !flag->plus)
	{
		*count += ft_putchar(' ');
		flag->width--;
	}
}
