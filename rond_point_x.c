/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/29 14:45:20 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces_x(unsigned int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_u(num);
	if (num == 0)
		width--;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

int	check_zero_is_flag_x(char *prs)
{
	int	i;

	i = 0;
	while (prs[i])
	{
		if (prs[i] == '0' && i > 0)
		{
			if (!ft_isdigit(prs[i - 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

void	first_condition_part_x(unsigned int num, int is_zero, t_val *flag,
		int *count)
{
	if (is_zero && !flag->precision && flag->width && !flag->minus)
		*count += ft_zero_x(num, flag->width);
	else if (flag->minus && flag->width && !flag->precision)
		*count += ft_minus_x(num, flag->width);
	else if (flag->minus && flag->width && flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_x(num, flag->after_width, flag->width);
	}
	else if (flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_x(num, flag->after_width, flag->width);
	}
	else if (flag->width && !flag->precision && !is_zero)
	{
		*count += add_spaces_x(num, flag->width);
		*count += ft_puthexa(num, 'x');
	}
	else if (count_val_flags(flag) == 0 && !flag->width)
		*count += ft_puthexa(num, 'x');
	else
		*count += ft_puthexa(num, 'x');
}

int	rond_point_x(t_val *flag, const char *str, unsigned int num)
{
	int	count;
	int	is_zero;
	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag_x(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_x(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
