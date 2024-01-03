/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/03 13:23:51 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_completion_of_minus_s(int width, int precision, char *arg,
		int *count)
{
	size_t	len;

	len = ft_strlen(arg);
	if (precision <= (int)len)
		len = (size_t)precision;
	if (width && !precision)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
	else
	{
		while (width-- - (int)len > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus_s(char *arg, int precision, int width)
{
	int		count;
	int		tmp;
	char	*tmp_arg;

	count = 0;
	tmp = precision;
	tmp_arg = arg;
	if (precision >= 6 && arg == NULL)
		count += ft_putstr("(null)");
	if (arg != NULL)
	{
		while ((precision--) > 0 && *arg)
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
	if (arg == NULL)
		return;

	(void)len;
	i = 0;
	while ((precision--) > 0 && arg[i])
	{
		*count += ft_putchar(arg[i]);
		i++;
	}
}

int	ft_precision_s(char *arg, int precision, int width)
{
	size_t	len;
	int		count;

	len = ft_strlen(arg);
	count = 0;
	if (precision <= (int)len)
		len = (size_t)precision;
	if (precision >= 6 && arg == NULL)
		len = 6;
	if (width && !precision)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while (width-- - (int)len > 0)
			count += ft_putchar(' ');
	}
	if (precision >= 6 && arg == NULL)
		count += ft_putstr("(null)");
	else
		ft_completion_of_regular_s(len, precision, arg, &count);
	return (count);
}
