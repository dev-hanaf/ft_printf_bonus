/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_val_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:56:18 by new               #+#    #+#             */
/*   Updated: 2023/12/24 04:43:58 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int count_val_flags(t_val *flag)
{
    int counter;

    counter = 0;
    if (flag->precision)
        counter++;
    if (flag->zero)
        counter++;
    if (flag->minus)
        counter++;
    if (flag->plus)
        counter++;
    if (flag->space)
        counter++;
    if (flag->hash)
        counter++; 
    if (flag->number)
        counter += flag->number;
    return (counter);
}
