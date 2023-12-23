/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/23 05:05:36 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# define NC	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAGENTA "\033[35m"
# define CYAN	"\033[36m"

# define FLAGS "diucspxX%"
typedef struct s_val
{
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
	int	precision;
	int start_index;
	int end_index;
}		t_val;

int		ft_printf(const char *str, ...);
void	ft_format(va_list ap, char f, int *count,int index);
t_val	ft_bonus(char f);
int		ft_check_flags(char f);

int		ft_isdigit(int c);
int		ft_putchar(char c);

int		ft_putnbr(t_val *flag, int num);

int ft_precision(t_val *flag);

#endif