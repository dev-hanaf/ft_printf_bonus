/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: new <new@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:14:30 by new               #+#    #+#             */
/*   Updated: 2024/01/04 04:47:38 by new              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main(void)
{
	int	y;
	int	x;

	// printf(v[1]	,(unsigned int)atoi(v[2]));
	// char	*n = v[2];
	// char n = 'a';
	// (void)c;
	// (void)v;
	// int n = atoi(v[2]);
	// unsigned int n2 = (uncsigned int)n;
	x = ft_printf("%5%");
	printf("\n");
	y = printf("%5%");
	printf("\n%d | %d", x, y);
}

// For /Users/new/francinette/tests/printf/printfTester/tests/dot_test.cpp:
// 57:     TEST(32, print(" %.9d ", INT_MIN));
// 63:     TEST(38, print(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// 87:     TEST(61, print(" %.9i ", INT_MIN));
// ...


// // // int main(void)
// // // {
// // //     unsigned int  n = 123;

// // //         // Vary width, precision, and the presence of '-' and '0' flags
// // //         printf(":%-5x:\n", n);
// // //         ft_printf(":%-5x:\n", n);
// // //         printf(":%-05x:\n", n);
// // //         ft_printf(":%-05x:\n", n);
// // //         printf(":%5x:\n", n);
// // //         ft_printf(":%5x:\n", n);
// // //         printf(":%05x:\n", n);
// // //         ft_printf(":%05x:\n", n);
// // //         printf(":%.2x:\n", n);
// // //         ft_printf(":%.2x:\n", n);

// // //         printf(":%.5x:\n", n);
// // //         ft_printf(":%.5x:\n", n);
// // //         printf(":%-5.2x:\n", n);
// // //         ft_printf(":%-5.2x:\n", n);
// // //         printf(":%-5.5x:\n", n);
// // //         ft_printf(":%-5.5x:\n", n);
// // //         printf(":%-05.2x:\n", n);
// // //         ft_printf(":%-05.2x:\n", n);
// // //         printf(":%05.5x:\n", n);
// // //         ft_printf(":%05.5x:\n", n);
// // //         printf(":%-10.2x:\n", n);
// // //         ft_printf(":%-10.2x:\n", n);
// // //         printf(":%-10.5x:\n", n);
// // //         ft_printf(":%-10.5x:\n", n);
// // //         printf(":%-010.2x:\n", n);
// // //         ft_printf(":%-010.2x:\n", n);
// // //         printf(":%010.5x:\n", n);
// // //         ft_printf(":%010.5x:\n", n);
// // //         printf("\n");

// // //     return (0);
// // // }

// // // int main(void)
// // // {
// // //     int n = 123;

// // //     // // Test 1
// // //     int x1 = ft_printf(":%d:", n);
// // //     puts("\n");
// // //     int y1 = printf(":%d:", n);
// // //     printf("\n%d %d\n", x1, y1);

// // //     // // Test 2
// // //     int x2 = ft_printf(":%10d:", n);
// // //     puts("\n");
// // //     int y2 = printf(":%10d:", n);
// // //     printf("\n%d %d\n", x2, y2);

// // //     // // Test 3
// // //     int x3 = ft_printf(":%.5d:", n);
// // //     puts("\n");
// // //     int y3 = printf(":%.5d:", n);
// // //     printf("\n%d %d\n", x3, y3);

// // //     // Test 4
// // //     int x4 = ft_printf(":%-10d:", n);
// // //     puts("\n");
// // //     int y4 = printf(":%-10d:", n);
// // //     printf("\n%d %d\n", x4, y4);

// // //     // // Test 5
// // //     int x5 = ft_printf(":%15.8d:", n);
// // //     puts("\n");
// // //     int y5 = printf(":%15.8d:", n);
// // //     printf("\n%d %d\n", x5, y5);

// // //     // // Test 6
// // //     int x6 = ft_printf(":%-15.8d:", n);
// // //     puts("\n");
// // //     int y6 = printf(":%-15.8d:", n);
// // //     printf("\n%d %d\n", x6, y6);

// // //     return (0);
// // // }

// // // int	main(void)
// // // {
// // // 	int	n;
// // // 	int	negative;

// // // 	n = -123;
// // // 	// Test 1: Basic width and precision
// // // 	ft_printf(":%5.d:\n", n);
// // // 	printf(":%5.d:\n", n);
// // // 	// Test 2: Left-justified with width and precision
// // // 	ft_printf(":%-10.5d:\n", n);
// // // 	printf(":%-10.5d:\n", n);
// // // 	// Test 3: Precision without width
// // // 	ft_printf(":%.3d:\n", n);
// // // 	printf(":%.3d:\n", n);
// // // 	// Test 5: Precision greater than the number's length
// // // 	ft_printf(":%.8d:\n", n);
// // // 	printf(":%.8d:\n", n);
// // // 	// Test 6: Precision and width with a negative number
// // // 	negative = -456;
// // // 	ft_printf(":%10.4d:\n", negative);
// // // 	printf(":%10.4d:\n", negative);
// // // 	return (0);
// // // }

// // // int	main(void)
// // // {
// // // 	int num = 422;

// // // 	// Experiment with different format specifiers
// // // 	printf(":1. %d:\n", num);
// // // 	ft_printf(":1. %d:\n", num);
// // // 	printf(":2. %.d:\n", num);
// // // 	ft_printf(":2. %.d:\n", num);
// // // 	printf(":3. %-.d:\n", num);
// // // 	ft_printf(":3. %-.d:\n", num);
// // // 	printf(":4. %0d:\n", num);
// // // 	ft_printf(":4. %0d:\n", num);
// // // 	printf(":5. %-0d:\n", num);
// // // 	ft_printf(":5. %-0d:\n", num);

// // // 	return (0);
// // // }