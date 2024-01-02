/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:01:37 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/29 09:12:34 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putaddresse_helper(unsigned long long num, int *count)
{
	if (num >= 16)
	{
		ft_putaddresse_helper(num / 16, count);
		num = num % 16;
	}
	*count += ft_putchar("0123456789abcdef"[num]);
}

int	ft_putaddresse(unsigned long long num)
{
	static int	count = 0;

	if (num == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	ft_putaddresse_helper(num, &count);
	return (count);
}
