/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:00:00 by new               #+#    #+#             */
/*   Updated: 2023/12/28 03:35:12 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_flags(char f)
{
	if (f == '.')
		return (1);
	if (f == '0')
		return (1);
	if (f == '-')
		return (1);
	if (f == '+')
		return (1);
	if (ft_isdigit(f))
		return (1);
	if (f == ' ')
		return (1);
	if (f == '#' || f == 'p')
		return (1);
	if (f == 'd' || f == 'i' || f == 'u')
		return (1);
	if (f == 'x' || f == 'X')
		return (1);
	if (f == 'c' || f == 's')
		return (1);
	if (f == '%')
		return (1);
	return (0);
}

void	ft_reset_t_val(t_val *flag)
{
	flag->precision = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->number = 0;
	flag->width = 0;
	flag->after_width = 0;
}

t_val	ft_bonus(char f, int mode)
{
	static t_val	flag;

	if (mode == 0)
	{
		if (f == '.')
			flag.precision = 1;
		if (f == '0')
			flag.zero = 1;
		if (f == '-')
			flag.minus = 1;
		if (f == '+')
			flag.plus = 1;
		if (f == ' ')
			flag.space = 1;
		if (f == '#')
			flag.hash = 1;
		if (ft_isdigit(f))
			flag.number += 1;
	}
	else
		ft_reset_t_val(&flag);
	return (flag);
}

void	ft_my_while(va_list ap, int *i, const char *str, t_format_args *args)
{
	while (ft_check_flags(str[*i]))
	{
		args->index = *i;
		ft_format(ap, str[*i], args);
		if (ft_mandatory_flags(str[*i]))
		{
			*i = *i + 1;
			break ;
		}
		*i = *i + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				i;
	int				count;
	t_format_args	args;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			args.count = &count;
			args.str = str;
			ft_my_while(ap, &i, str, &args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
