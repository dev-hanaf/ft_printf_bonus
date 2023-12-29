/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_x_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/29 07:02:39 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces_x_X(unsigned int num, int width)
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

int	check_zero_is_flag_x_X(char *prs)
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

void	first_condition_part_x_X(unsigned int num, int is_zero, t_val *flag,
		int *count)
{
	if (is_zero && !flag->precision && flag->width && !flag->minus)
		*count += ft_zero_x_X(num, flag->width);
	else if (flag->minus && flag->width && !flag->precision)
		*count += ft_minus_x_X(num, flag->width);
	else if (flag->minus && flag->width && flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_x_X(num, flag->after_width, flag->width);
	}
	else if (flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_x_X(num, flag->after_width, flag->width);
	}
	else if (flag->width && !flag->precision && !is_zero)
	{
		*count += add_spaces_x_X(num, flag->width);
		*count += ft_puthexa(num, 'x');
	}
	else if (count_val_flags(flag) == 0 && !flag->width)
		*count += ft_puthexa(num, 'x');
	else
		*count += ft_puthexa(num, 'x');
}

int	rond_point_x_X(t_val *flag, const char *str, unsigned int num, char f)
{
	int	count;
	int	is_zero;
	(void)f; 
	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag_x_X(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_x_X(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
