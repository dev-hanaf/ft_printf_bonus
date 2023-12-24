/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2023/12/24 05:48:11 by new              ###   ########.fr       */
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

int counter_number(int num)
{
    int i = 0;
    
    if (num == 0)
        return (1);
    if (num < 0)
    {
        num *= -1;
        i++;
    }
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}


int ft_precision(t_val *flag, const char *str, int num)
{
    flag->start_index = flag->end_index  - count_val_flags(flag);
    char *prs = ft_parser(str, flag->start_index, flag->end_index);
    int i = 0;
    int width = 0;
    int precision = 0;
    
    while (prs[i] != '.')
    {
        if (ft_isdigit(prs[i]))
            width = width * 10 + (prs[i] - '0');
        i++;
    }
    i++;
    while (prs[i])
    {
        if (ft_isdigit(prs[i]))
            precision = precision * 10 + (prs[i] - '0');
        i++;
    }

    
    int len = counter_number(num);
    printf(RED"len %d\n"NC,len);

    if (width > (len + precision))
    {
        if (num < 0)
            width--;
        while ((width - precision) > 0)
        {
            printf(" ");
            width--;
        }
    }
    if (num < 0)
    {
        printf("-");
        num *= -1;
    }
    if (precision > len)
    {
        while ((precision - len) >= 0)
        {
            printf("0");
            precision--;
        }   
    }
    printf("%d",num);

    
    free(prs);
    return (0);
}
    // printf("%s\n",prs);
    // printf(CYAN"width => %d\n"NC,width);
    // printf(GREEN"precision => %d\n"NC,precision); 
    
    // puts("\n");

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