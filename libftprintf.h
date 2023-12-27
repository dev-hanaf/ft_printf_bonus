/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/27 13:49:23 by ahanaf           ###   ########.fr       */
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
	char		*prs;
	int			plus;
	int			minus;
	int			zero;
	int			number;
	int			space;
	int			hash;
	int			precision;
	int			width;
	int			after_width;
	int			start_index;
	int			end_index;
}				t_val;

typedef struct s_format_args
{
	int			*count;
	int			index;
	const char	*str;
}				t_format_args;

// ft_fromat.c
void			ft_format(va_list ap, char f, t_format_args *args);

// ft_printf.c
int				ft_check_flags(char f);
void			ft_reset_t_val(t_val *flag);
t_val			ft_bonus(char f, int mode);
int				ft_mandatory_flags(char f);
void			ft_my_while(va_list ap, int *i, const char *str,
					t_format_args *args);
int				ft_printf(const char *str, ...);

// ft_utils.c
int				ft_isdigit(int c);
int				ft_putchar(char c);

// ft_dicimal.c
int				ft_putnbr(int num);
int				ft_putnbr_u(unsigned int n);

int				count_val_flags(t_val *flag);

char			*ft_parser(const char *str, int start, int end);
int				counter_number(int num);
int				counter_number_u(unsigned int num);
int				ft_minus(int num, int width);
int				ft_minus_u(unsigned int num, int width);
int				ft_width(char *prs);
int				ft_get_precision(char *prs);
int				ft_precision(int num, int precision, int width);
int				ft_precision_u(unsigned int num, int precision, int width);

int				ft_precision_of_minus(int num, int precision, int width);
int				ft_precision_of_minus_u(unsigned int num, int precision,
					int width);

int				ft_zero(int num, int width);
int				ft_zero_u(unsigned int num, int width);

int				rond_point(t_val *flag, const char *str, int num);
int				rond_point_u(t_val *flag, const char *str, unsigned int num);

#endif