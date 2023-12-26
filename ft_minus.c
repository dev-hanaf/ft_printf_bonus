/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:14:00 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 02:27:45 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_minus(int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number(num);
	count += ft_putnbr(num);
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}
