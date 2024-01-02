/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/02 19:09:10 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_width(int num, int is_zero, t_val *flag, int *count)
{
	if (flag->minus)
	{
		if (!flag->plus)
			ft_print_space(num, count, flag);
		ft_print_plus_minus(num, count, flag);
		*count += ft_minus(num, flag->width);
	}
	else if (is_zero)
	{
		ft_print_plus_minus(num, count, flag);
		*count += ft_zero(num, flag->width);
	}
	else
	{
		if (flag->plus && num >= 0)
			flag->width--;
		*count += add_spaces(num, flag->width);
		ft_print_plus_minus(num, count, flag);
		*count += ft_putnbr(num);
	}
}

void	handle_width_precision(int num, t_val *flag, int *count)
{
	if (flag->minus)
	{
		ft_print_space(num, count, flag);
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus(num, flag);
	}
	else
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision(num, flag);
	}
}

void	first_condition_part(int num, int is_zero, t_val *flag, int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_putnbr(num);
	else if (flag->width && !flag->precision)
		handle_width(num, is_zero, flag, count);
	else if (flag->width && flag->precision)
		handle_width_precision(num, flag, count);
	else
	{
		if (!flag->plus)
			ft_print_space(num, count, flag);
		ft_print_plus_minus(num, count, flag);
		*count += ft_putnbr(num);
	}
}

int	rond_point(t_val *flag, const char *str, int num)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
