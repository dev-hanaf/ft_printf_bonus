/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:02:40 by new               #+#    #+#             */
/*   Updated: 2024/01/03 20:14:59 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	counter_number(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	counter_number_u(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	counter_number_x(unsigned int num, t_val *flag)
{
	int	i;

	i = 0;
	if (num != 0 && flag->hash)
		i += 2;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	counter_number_p(unsigned long long  num)
{
	int	i;

	i = 0;
	if (!num)
		return (5);
	// if (num != 0)
	// 	i += 1;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}
