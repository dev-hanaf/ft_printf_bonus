/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:55:05 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/06 08:50:09 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libftprintf.h"
#include "libft/libft.h"

static int ft_hashtag(char *check_x,char *check_X)
{
    int lenght;

    lenght = 0;
    if(check_x)
    {
     lenght =  write(1, "0x",2);
    }
    else if(check_X)
    {
        lenght = write(1, "0X",2);
    }
    return lenght;
}

static int ft_printf_char(int c)
{
    int lenght;
    
    lenght = 0;
    lenght =  write (1, &c, 1);
    return (lenght);
}


static int ft_printf_hexa(int n, char fomrat)
{
    static int lenght = 0;
    char *x = "0123456789abcdef";
    char *X = "0123456789ABCDEF";

    //printf("lenght %d\n",lenght);
    if (fomrat == 'x')
    {
        if (n < 16)
            lenght += ft_putchar_fd(x[n],1);   
        else
        {
            ft_printf_hexa(n / 16, fomrat);
            lenght += ft_putchar_fd(x[n % 16],1);   
        }
    }
    else if (fomrat == 'X')
    {
        if (n < 16)
        {
            lenght += ft_putchar_fd(X[n],1);   
        }
        else
        {
            ft_printf_hexa(n / 16, fomrat);
            lenght += ft_putchar_fd(X[n % 16],1);
        }
    }
    return (lenght);
}

static int ft_print_dot(int num)
{
  
    int len = 0;
    num = num -2;
    while(num-- > 0)
    {
        len += ft_putchar_fd('0',1);
    }
    return (len);
} 

static char *parser(const char *str)
{
    size_t i = 0;
    char *res;
    int index = 0;
    char *formats = ".+- 0#csdixXpu%";
    int j = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            j = 0;
            while(formats[j])
            {
                if (str[i] == formats[j])
                { 
                    res[index] = str[i];
                    index++;
                    i++;
                }
                j++;
            }
        }
        i++;
    }
    res[index] = '\0';
    return (res);
}

int main()
{
    printf("%s\n",parser("%d.0#x"));
}
// int ft_printf(const char *str, ...)
// {
//     va_list ap;
    
//     va_start(ap, str);
    
//     int print_lenght;
//     int i;

//     i = 0;
//     print_lenght = 0;
//     while (str[i])
//     {
//         if (str[i] == '%')
//         {
//             i++;
//             while (str[i] && ft_strchr("cspdiuxX.*-+0123456789#%", str[i]))
//             {
//                 if (str[i] == '#')
//                 {
//                     // need to fixe it
//                     print_lenght += ft_hashtag(ft_strchr(str, 'x'), ft_strchr(str, 'X'));       

//                 }
//                 else if (str[i] == '.')
//                 {
//                     i++;
//                     int precision = 0;
//                     while (ft_isdigit(str[i]))
//                     {
//                         precision = (precision * 10);
//                         precision = precision + (str[i] - '0');

//                         i++;
//                     }
//                     print_lenght += ft_print_dot(precision);
//                     i--; 
//                 }
//                 else if (str[i] == 'x' || str[i] == 'X')
//                     print_lenght += ft_printf_hexa(va_arg(ap, unsigned int),str[i]);
//                 else if (str[i] == 'd' || str[i] == 'i')
//                     print_lenght += ft_putnbr_fd(va_arg(ap, int),1);
//                 else if (str[i] == 'c')
//                     print_lenght += ft_putchar_fd(va_arg(ap, int),1);
//                 else if (str[i] == 's')
//                     print_lenght += ft_putstr_fd(va_arg(ap, char *),1);
//                 else if (str[i] == 'p')
//                 {
//                     void *ptr = va_arg(ap, void *);
//                     if (ptr)
//                         print_lenght += ft_print_address(ptr);
//                     print_lenght += ft_putstr_fd("0x0", 1);
//                 }
//                 else if (str[i] == '%')
//                     print_lenght += ft_putchar_fd('%', 1);
//                 i++;
                
//             }
//         }
//         if(str[i] == '\n')
//             print_lenght += write(1, "\n", 1);
//         else
//             print_lenght += write(1, &str[i], 1);
//         i++;    
//     }
//     va_end(ap);
//     return (print_lenght);
            
// }

// int main ()
// {
//     int n;
    
//     //n += ft_printf("%#.10x",100);
//     //printf("\nn = %d\n",n);
//     n= 0;
//     char x;
//     n += ft_printf(":%s %c %d %X %X %p:\n","hello world",'c',100,5000,100,&x);
//     printf("%d\n",n);
//     n= 0;
//     n += printf(":%s %c %d %X %X %p:\n","hello world",'c', 100,5000,100,&x);
//     printf("%d\n",n);
    

    // n = 0;
    // n += ft_printf("dyali => %#1.X\n", 1);  // Should print "0x2a"
    // printf("%d\n",n);
    // n = 0;
    // n += printf("dyalo => %#1.3X\n", 1);  // Should print "0x2a"
    // printf("%d\n",n);

    //n += printf("%#.10x",100);
    //printf("\nn = %d\n",n);
   // n += ft_printf("%#.0d\n", 0);   // Should print "0"
   // n += ft_printf("%#.0d\n", 42);  // Should print "42"
   // n += ft_printf("%#.5d\n", 0);   // Should print "00000"
   // n += ft_printf("%#.5d\n", 42);  // Should print "00042"
//     n += ft_printf("dyali => %#.0x\n", 0);   // Should print "0x0"
//     n += ft_printf("dyali => %#.0x\n", 42);  // Should print "0x2a"
//     n += ft_printf("dyali => %#.5x\n", 0);   // Should print "0x00000"
//     n += ft_printf("dyali => %#.5x\n", 42);  // Should print "0x0002a"
    
//     printf("n => %d ",n );

//     puts("\ndyalhom");
//     n = 0;
//     //n += printf("%#.10x",100);
//     //printf("\nn = %d\n",n);
//     //n += printf("%#.0d\n", 0);   // Should print "0"
//     //n += printf("%#.0d\n", 42);  // Should print "42"
//    // n += printf("%#.5d\n", 0);   // Should print "00000"
//    // n += printf("%#.5d\n", 42);  // Should print "00042"
//     n += printf("dyalo => %#.0x\n", 0);   // Should print "0x0"
//     n += printf("dyalo => %#.0x\n", 42);  // Should print "0x2a"
//     n += printf("dyalo => %#.5x\n", 0);   // Should print "0x00000"
//     n += printf("dyalo => %#.5x\n", 42);  // Should print "0x0002a"

//     printf("n => %d ",n );
//}


// testing #
/*int main() {
    // Testing # with different specifiers
    //printf("%#o\n", 42);   // Octal with 0 prefix
    printf("%#x\n", 255);  // Hexadecimal with 0x prefix
    printf("%#.3X\n", 255);  // Hexadecimal with 0X prefix
    //printf("%#f\n", 3.14); // Floating-point with decimal point
   //printf("%#e\n", 0.001); // Scientific notation with decimal point


    return 0;
}*/

/*int main() {
    // // Pointer
    // int value = 42;
    // printf("%p\n", (void*)&value);
    // // Integer
    // printf("%d\n", 123);
    // // String
    // printf("%s\n", "Hello, World!");
    // // Character
    // printf("%c\n", 'A');
    // // Hexadecimal
    // printf("%x\n", 255);  
    // // Unsigned Integer
    // printf("%u\n", 456);
    // Octal
    //printf("%o\n", 63);
    // Scientific Notation
    //printf("%e\n", 0.00123);


    printf("%.5d\n",45);

    printf("%+5d\n",45);


    printf("%-5d\n",45);

    
    //printf("%-d", –2147483648);
    
    return 0;
}*/

