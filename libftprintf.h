/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/25 02:37:47 by ahanaf           ###   ########.fr       */
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

# define NC "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

# define FLAGS "diucspxX%"
typedef struct s_val
{
	int	plus;
	int	minus;
	int	zero;
	int	number;
	int	space;
	int	hash;
	int	precision;
	int	start_index;
	int	end_index;
}		t_val;

int		ft_printf(const char *str, ...);
void	ft_format(va_list ap, char f, int *count, int index, const char *str);
t_val	ft_bonus(char f, int mode);
int		ft_check_flags(char f);

int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putnbr(int num);

int		count_val_flags(t_val *flag);

char	*ft_parser(const char *str, int start, int end);
int		counter_number(int num);
int		ft_minus(int num, int width);
int		ft_width(char *prs);
int		ft_get_precision(char *prs);
int		ft_precision(int num, int precision, int width);
int		ft_precision2(int num, int precision, int width);
int ft_zero(int num, int width);

int		rond_point(t_val *flag, const char *str, int num);

#endif