/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:11:05 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/26 00:11:30 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_mandatory_flags(char f)
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
