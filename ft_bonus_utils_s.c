/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:50 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/03 20:14:59 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_spaces_s(char *arg, int width)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen(arg);
	while (width - (int)len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	check_zero_is_flag_s(char *prs)
{
	int	i;

	i = 0;
	while (prs[i])
	{
		if (prs[i] == '0' && i > 0)
		{
			if (!ft_isdigit(prs[i - 1]))
				return (1);
		}
		i++;
	}
	return (0);
}
