/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:01:37 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/03 21:12:13 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddresse(unsigned long long num)
{
	char	*base = "0123456789abcdef";
	
	int		count;

	count = 0;
	if (num < 16)
	{
		count++;
		write(1, &base[num], 1);
	}
	else
	{
		count += ft_putaddresse(num / 16);
		count += ft_putaddresse((num % 16));
	}
	return (count);
}