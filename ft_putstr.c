/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:38:49 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/04 01:14:57 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}
