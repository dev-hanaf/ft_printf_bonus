/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/29 14:55:40 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces_p(unsigned long long num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_p(num);
	if (num == 0)
		width--;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

int	check_zero_is_flag_p(char *prs)
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

void	first_condition_part_p(unsigned long long num, int is_zero, t_val *flag,
		int *count)
{
	if (is_zero && !flag->precision && flag->width && !flag->minus)
		*count += ft_zero_p(num, flag->width);
	else if (flag->minus && flag->width && !flag->precision)
		*count += ft_minus_p(num, flag->width);
	else if (flag->minus && flag->width && flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_p(num, flag->after_width, flag->width);
	}
	else if (flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_p(num, flag->after_width, flag->width);
	}
	else if (flag->width && !flag->precision && !is_zero)
	{
		*count += add_spaces_p(num, flag->width);
		*count += ft_putaddresse(num);
	}
	else if (count_val_flags(flag) == 0 && !flag->width)
		*count += ft_putaddresse(num);
	else
		*count += ft_putaddresse(num);
}

int	rond_point_p(t_val *flag, const char *str, unsigned long long num)
{
	int	count;
	int	is_zero;
	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag_p(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_p(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}