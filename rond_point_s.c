/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/02 18:47:52 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces_s(char *arg, int width)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen(arg);
	while (width - (int)len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	check_zero_is_flag_s(char *prs)
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

void	first_condition_part_s(char *arg, t_val *flag, int *count)
{
	if (flag->minus && flag->width && !flag->precision)
		*count += ft_minus_s(arg, flag->width);
	else if (flag->minus && flag->width && flag->precision)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_s(arg, flag->after_width, flag->width);
	}
	else if (flag->precision && flag->width)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_s(arg, flag->after_width, flag->width);
	}
	else if (flag->precision)
	{
		return ;
	}
	else if (flag->width && !flag->precision)
	{
		*count += add_spaces_s(arg, flag->width);
		*count += ft_putstr(arg);
	}
	else
		*count += ft_putstr(arg);
}

int	rond_point_s(t_val *flag, const char *str, char *arg)
{
	int	count;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	// is_zero = check_zero_is_flag_s(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_s(arg, flag, &count);
	free(flag->prs);
	return (count);
}
