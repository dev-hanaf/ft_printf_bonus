/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:00:56 by new               #+#    #+#             */
/*   Updated: 2023/12/24 05:11:14 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

//	printf("\033[0;33mflag => point %d\n", flag->precision);
// printf("flag => zero %d\n", flag->zero);
// printf("flag => minus %d\n", flag->minus);
// printf("flag => plus %d\n", flag->plus);
// printf("flag => space %d\n", flag->space);
// printf("flag => hash %d\033[0;0m\n", flag->hash);