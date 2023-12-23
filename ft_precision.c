/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/23 05:08:25 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_precision(t_val *flag)
{
    printf("\033[0;33mflag => point %d\n", flag->precision);
    printf("flag => zero %d\n", flag->zero);
    printf("flag => minus %d\n", flag->minus);
    printf("flag => plus %d\n", flag->plus);
    printf("flag => space %d\n", flag->space);
    printf("flag => hash %d\033[0;0m\n", flag->hash);
    printf("flag => start index %d\033[0;0m\n", flag->start_index);
    printf("flag => end index %d\033[0;0m\n", flag->end_index);


    return (0);
}