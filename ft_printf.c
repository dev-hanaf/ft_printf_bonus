/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:00:00 by new               #+#    #+#             */
/*   Updated: 2023/12/23 05:15:48 by new              ###   ########.fr       */
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

t_val	ft_bonus(char f)
{
	static t_val	flag;

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
	printf("\033[0;32mflag => point %d\n", flag.precision);
	printf("flag => zero %d\n", flag.zero);
	printf("flag => minus %d\n", flag.minus);
	printf("flag => plus %d\n", flag.plus);
	printf("flag => space %d\n", flag.space);
	printf("flag => hash %d\033[0;0m\n", flag.hash);
	return (flag);
}

void	ft_format(va_list ap, char f, int *count,int index)
{
	t_val	flag;
	static int is_ok;

	flag = ft_bonus(f);
	if(!is_ok)
		flag.start_index = index;
	is_ok = 1;
	if (f == 'd')
	{
		flag.end_index = index;
		is_ok = 0;
		*count += ft_putnbr(&flag, va_arg(ap, int));
	}
	else if (f == 'c')
		*count += ft_putchar(va_arg(ap, int));
	
	else if (f == '%')
		*count += ft_putchar('%');
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
				ft_format(ap, str[i], &count, i);
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
