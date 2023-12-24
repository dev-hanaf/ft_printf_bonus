/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/24 03:56:40 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


//end +1 to included the formats by example %-+d   in this case we add 1 to end to include d
char *ft_parser(const char *str,int start, int end)
{
    char *prs;
    prs = (char *)malloc(sizeof(char) * ((end + 1) - start + 1));
    if (!prs)
        return (NULL);
    int i = 0;
    while (i <= end - start)
    {
        prs[i] = str[start + i];
        i++;
    }
    prs[i] = '\0';
    return (prs);
}
int ft_precision(t_val *flag, const char *str)
{
    flag->start_index = flag->end_index  - count_val_flags(flag);
    char *prs = ft_parser(str, flag->start_index, flag->end_index);
    int i = 0;
    int width = 0;
    int precision = 0;
    
    while (prs[i] != '.' && prs[i])
    {
        if (ft_isdigit(prs[i]))
            width = width * 10 + (prs[i] - '0');
        i++;
    }
    i = 0;
    while (prs[i])
    {
        if (i == '.')
        {
            i++;
            while (ft_isdigit(prs[i]))
            {
                precision = precision * 10 + (prs[i] - '0');
                i++;
            }
        }
        i++;
    }
    printf(CYAN"%d\n"NC,width);
    printf(RED"%d\n"NC,precision);    

    free(prs);
    return (0);
}


    // printf(BLUE"%d",count_val_flags(flag));
    
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