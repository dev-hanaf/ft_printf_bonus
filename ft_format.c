/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:47 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/26 01:46:39 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// on the line 91 mode to reset my structure t_val to 0

void	ft_format(va_list ap, char f, t_format_args *args)
{
	static t_val	flag;
	static int		mode;

	if (ft_mandatory_flags(f) == 0)
		mode = 0;
	flag = ft_bonus(f, mode);
	if (f == 'd')
	{
		flag.end_index = args->index;
		*(args->count) += rond_point(&flag, args->str, va_arg(ap, int));
		mode = 1;
		flag = ft_bonus(f, mode);
	}
	else if (f == 'i')
	{
		flag.end_index = args->index;
		*(args->count) += rond_point(&flag, args->str, va_arg(ap, int));
		mode = 1;
		flag = ft_bonus(f, mode);
	}
	else if (f == 'c')
		*(args->count) += ft_putchar(va_arg(ap, int));
	else if (f == '%')
		*(args->count) += ft_putchar('%');
}
