/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils_xxx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:50 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/03 20:29:54 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_spaces_xx(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_x(num, flag);
	if (num == 0)
		width--;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

void	ft_print_plus_xx(unsigned int num, int *count, t_val *flag)
{
	if (flag->plus)
	{
		flag->width--;
		*count += add_spaces_xx(num, flag->width, flag);
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_plus_minus_xx(int *count, t_val *flag)
{
	if (flag->plus)
	{
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_space_xx(int *count, t_val *flag)
{
	if (flag->space && !flag->plus)
	{
		*count += ft_putchar(' ');
		flag->width--;
	}
}
