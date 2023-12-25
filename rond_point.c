/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 18:57:58 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	add_spaces(int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number(num);
	if (num == 0)
		width--;
	if (num < 0)  
		num *= -1;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

int check_zero_is_flag(char *prs)
{
    int i;

    i = 0;
    while (prs[i])
    {
        if (prs[i] == '0' && i > 0)
        {
           if (!ft_isdigit(prs[i - 1]))
                return 1; 
        }
        i++;
    }
    return 0;
}
int	rond_point(t_val *flag, const char *str, int num)
{
	char	*prs;
	int		count;
	int		width;
	int		precision;
	flag->start_index = flag->end_index - count_val_flags(flag);
	prs = ft_parser(str, flag->start_index, flag->end_index);
    if (!prs)
        return 0;
    int is_zero = check_zero_is_flag(prs);
    
	// int i = 0;
	count = 0;
	width = ft_width(prs);
	// printf(RED"%d\n"NC,width);
	precision = 0;

    if (is_zero && flag->precision && width)
        count += ft_zero(num, width);
    else if (flag->minus && width && !flag->precision)
		count += ft_minus(num, width);
	else if (flag->minus && width && flag->precision)
	{
		precision = ft_get_precision(prs);
		count += ft_precision2(num, precision, width);
	}
	else if (flag->precision)
	{
		precision = ft_get_precision(prs);
		count += ft_precision(num, precision, width);
	}
	else if (width && !flag->precision )
	{
		count += add_spaces(num, width);
		count += ft_putnbr(num);
	}
	else if (count_val_flags(flag) == 0 && !width)
		count += ft_putnbr(num);
	else 
        count += ft_putnbr(num);
	free(prs);
	return (count);
}
// printf(RED"\n--------------------------------------------\n"NC);
// printf(CYAN"%s\n"NC,ft_parser(str, flag->start_index, flag->end_index));
// printf("\033[0;33mflag => precision %d\n", flag->precision);
// printf("flag => zero %d\n", flag->zero);
// printf("flag => minus %d\n", flag->minus);
// printf("flag => plus %d\n", flag->plus);
// printf("flag => space %d\n", flag->space);
// printf("flag => hash %d\n", flag->hash);
// printf("flag => start index %d\n", flag->start_index);
// printf("flag => end index %d\033[0;0m\n", flag->end_index);