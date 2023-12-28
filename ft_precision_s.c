/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/28 03:08:38 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_completion_of_minus_s(int width, int precision, char *arg,
		int *count)
{
	size_t	len;

	len = ft_strlen(arg);
	if (width > (int)len && width > precision)
	{
		if (precision > (int)len)
		{
			width -= precision;
			while (width-- > 0)
				*count += ft_putchar(' ');
		}
		else
		{
			width -= (int)len;
			while (width-- > 0)
				*count += ft_putchar(' ');
		}
	}
}

int	ft_precision_of_minus_s(char *arg, int precision, int width)
{
	size_t	len;
	int		count;
	int		tmp;
	char *		tmp_arg;

	count = 0;
	len = ft_strlen(arg);
	tmp = precision;
	tmp_arg = arg;
	if (precision > (int)len)
	{
		while ((precision-- - (int)len) > 0)
		{
			count += ft_putchar(*arg);
			arg++;
		}
	}
	ft_completion_of_minus_s(width, tmp, tmp_arg, &count);
	return (count);
}

void	ft_completion_of_regular_s(size_t len, int precision, char *arg,
		int *count)
{
	int	i;

	i = 0;
	if (precision > (int)len)
	{
		while ((precision-- - (int)len) > 0)
		{
			*count += ft_putchar(arg[i]);
			i++;
		}
	}
}

int	ft_precision_s(char *arg, int precision, int width)
{
	size_t	len;
	int		count;

	len = ft_strlen(arg);
	count = 0;
	if (width && !precision)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	else if (width > precision && width > (int)len)
	{
		if (precision)
		{
			width -= precision;
		}
		else
			width -= (int)len;
		while (width--)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular_s(len, precision, arg, &count);
	return (count);
}
