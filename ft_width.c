/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:26:04 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 01:36:39 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_width(char *prs)
{
    int i = 0;
    int width = 0;
    while (prs[i])
    {
        if(ft_isdigit(prs[i]))
        {
            width = width * 10 + (prs[i] - '0');
            if (!ft_isdigit(prs[i + 1]))
                return (width);  
        }
        i++;
     
    }
    return (width);
}
