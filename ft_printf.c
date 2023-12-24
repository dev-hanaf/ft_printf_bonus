/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:00:00 by new               #+#    #+#             */
/*   Updated: 2023/12/24 05:04:43 by new              ###   ########.fr       */
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
	}else
	{
		flag.precision = 0;
		flag.zero = 0;
		flag.minus = 0;
		flag.plus = 0;
		flag.space = 0;
		flag.hash = 0;
		flag.number = 0;
	}
	return (flag);
}

int ft_mandatory_flags(char f)
{
	if (f == 'p')
		return (1);
	if (f == 'd' || f == 'i' || f == 'u')
		return (1);
	if (f == 'x' || f == 'X')
		return (1);
	if (f == 'c' || f == 's')
	if (f == '%')
		return (1);
	return (0);
}
// on the line 91 mode to reset my structure t_val to 0

void	ft_format(va_list ap, char f, int *count,int index,const char *str)
{
	static t_val	flag;
	static int mode;
	if (ft_mandatory_flags(f) == 0)
		mode = 0;
	flag = ft_bonus(f, mode);
	if (f == 'd')
	{
		flag.end_index = index;
		ft_precision(&flag, str,va_arg(ap,int));
		// *count += ft_putnbr(&flag, va_arg(ap, int));
		mode = 1;
		flag = ft_bonus(f, mode);
	}
	else if (f == 'c')
		*count += ft_putchar(va_arg(ap, int));
	
	else if (f == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (ft_check_flags(str[i]))
			{
				ft_format(ap, str[i], &count, i,str);
				if(ft_mandatory_flags(str[i]))
					break ;
				i++;
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
