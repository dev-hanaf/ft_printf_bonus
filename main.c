/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:14:30 by new               #+#    #+#             */
/*   Updated: 2024/01/05 05:08:10 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main(void)
{
	int	y = 0;
	int	x = 0;

	// printf(v[1]	,(unsigned int)atoi(v[2]));
	// char	*n = v[2];
	// char n = 'a';
	// (void)c;
	// (void)v;
	// int n = atoi(v[2]);
	// unsigned int n2 = (uncsigned int)n;
	// x = ft_printf(" %.1x ", 0);
	// printf("\n");
	// y = printf(" %.1x ", 0);
	// printf("\n%d | %d", x, y);
	x += ft_printf(":%5.0u:", 0);
	//x += ft_printf("%5.u", 0);
	//x +=ft_printf("%-5.0u", 0);
	//x +=ft_printf("%-5.u", 0);
	// x +=ft_printf("%.0x", 0);
	// x +=ft_printf("%.x", 0);
	// x +=ft_printf("%5.0x", 0);
	// x +=ft_printf("%5.x", 0);
	// x +=ft_printf("%-5.0x", 0);
	// x +=ft_printf("%-5.x", 0);
	// x +=ft_printf("%.0x", 0);
	// x +=ft_printf("%.x", 0);
	// x +=ft_printf("%5.0x", 0);
	// x +=ft_printf("%5.x", 0);
	// x +=ft_printf("%-5.0x", 0);
	// x +=ft_printf("%-5.x", 0);
	// x +=ft_printf("%.0X", 0);
	// x +=ft_printf("%.X", 0);
	// x +=ft_printf("%5.0X", 0);
	// x +=ft_printf("%5.X", 0);
	printf("\n");
	y += printf(":%5.0u:", 0);
	//y += printf("%5.u", 0);
	//y += printf("%-5.0u", 0);
	//y += printf("%-5.u", 0);
	// y += printf("%.0x", 0);
	// y += printf("%.x", 0);
	// y += printf("%5.0x", 0);
	// y += printf("%5.x", 0);
	// y += printf("%-5.0x", 0);
	// y += printf("%-5.x", 0);
	// y += printf("%.0x", 0);
	// y += printf("%.x", 0);
	// y += printf("%5.0x", 0);
	// y += printf("%5.x", 0);
	// y += printf("%-5.0x", 0);
	// y += printf("%-5.x", 0);
	// y += printf("%.0X", 0);
	// y += printf("%.X", 0);
	// y += printf("%5.0X", 0);
	// y += printf("%5.X", 0);


		//  x = ft_printf("^.^/%010.1u^.^/",0);
		// printf("\n"GREEN);
		//  y = printf("^.^/%010.1u^.^/", 0);

		printf(NC"\n%d %d",x, y);
// ft_printf("%5p, %5p, %5p, %5p, %5p, %5p", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352): returned: 92, but expected: 94
// Error in test 3: ft_printf("%5p, %5p, %5p, %5p, %5p, %5p", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352): different memory
}
// 125:    TEST(97, print(" %.1x ", 0));
// 149:    TEST(121, print(" %.11x ", LONG_MIN));
// 153:    TEST(125, print(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// 155:    TEST(126, print(" %.1X ", 0));
// 179:    TEST(150, print(" %.11X ", LONG_MIN));
// 183:    TEST(154, print(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));


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