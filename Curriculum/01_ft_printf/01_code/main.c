/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 14:52:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{

	printf("*** main test started ***\n");
	printf("|-- test printf -->\n");
	// // ft_printf("c%cs%sp%pd%di%iu%ux%xX%X%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// // ft_printf("%cc%ss%pp%dd%ii%uu%xx%XX%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);

	int		n;

	n = 0;
	n = ft_printf("-->keki<--\n-->%c%c%c%c<--\n", 'k', 'e', 'k', 'i');
	ft_printf("n: %i\n", n);
	n = ft_printf("--> <--\n-->%c<--\n", '\0');
	ft_printf("n: %i\n", n);
	n = ft_printf("-->\n<--\n-->%c<--\n", '\n');
	ft_printf("n: %i\n", n);
	n = ft_printf("--><--\n-->%s<--\n", "");
	ft_printf("n: %i\n", n);
	n = ft_printf("-->Keki<--\n-->%s<--\n", "Keki");
	ft_printf("n: %i\n", n);
	n = ft_printf("-->%<--\n-->%%<--\n", '%');
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0<--\n-->%i<--\n", 0);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->123<--\n-->%i<--\n", 123);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->-123<--\n-->%d<--\n", -123);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->2147483647<--\n-->%d<--\n", 2147483647);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->-2147483648<--\n-->%d<--\n", -2147483648);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0<--\n-->%u<--\n", 0);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->4294967295<--\n-->%u<--\n", 2147483647 + 2147483648);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0<--\n-->%u<--\n", 2147483647 + 2147483648 + 1);
	ft_printf("n: %i\n", n);

	n = printf("-->0<--\n-->%x<--\n", 0);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0<--\n-->%x<--\n", 0);
	ft_printf("n: %i\n", n);
	n = printf("-->a<--\n-->%x<--\n", 10);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->a<--\n-->%x<--\n", 10);
	ft_printf("n: %i\n", n);
	n = printf("-->13<--\n-->%x<--\n", 19);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->13<--\n-->%x<--\n", 19);
	ft_printf("n: %i\n", n);
	n = printf("-->7c0<--\n-->%x<--\n", 1984);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->7c0<--\n-->%x<--\n", 1984);
	ft_printf("n: %i\n", n);

	n = ft_printf("-->0<--\n-->%X<--\n", 0);
	ft_printf("n: %i\n", n);
	n = printf("-->0<--\n-->%X<--\n", 0);
	ft_printf("n: %i\n", n);
	n = printf("-->A<--\n-->%X<--\n", 10);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->A<--\n-->%X<--\n", 10);
	ft_printf("n: %i\n", n);
	n = printf("-->13<--\n-->%X<--\n", 19);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->13<--\n-->%X<--\n", 19);
	ft_printf("n: %i\n", n);
	n = printf("-->7C0<--\n-->%X<--\n", 1984);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->7C0<--\n-->%X<--\n", 1984);
	ft_printf("n: %i\n", n);

	n = ft_printf("-->0<--\n-->%p<--\n", 0);
	ft_printf("n: %i\n", n);
	n = printf("-->0x1<--\n-->%p<--\n", 1);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0x1<--\n-->%p<--\n", 1);
	ft_printf("n: %i\n", n);
	n = printf("-->0x7C0<--\n-->%p<--\n", 1984);
	ft_printf("n: %i\n", n);
	n = ft_printf("-->0x7C0<--\n-->%p<--\n", 1984);
	ft_printf("n: %i\n", n);

	n = printf("-->without args<--\n");
	ft_printf("n: %i\n", n);
	n = ft_printf("-->without args<--\n");
	ft_printf("n: %i\n", n);

	n = printf("");
	ft_printf("n: %i\n", n);
	n = ft_printf("");
	ft_printf("n: %i\n", n);
	n = printf(" ");
	printf("n: %i\n", n);
	n = ft_printf(" ");
	ft_printf("n: %i\n", n);
	n = printf(0);
	ft_printf("n: %i\n", n);
	n = ft_printf(0);
	ft_printf("n: %i\n", n);
	n = printf(NULL);
	ft_printf("n: %i\n", n);
	n = ft_printf(NULL);
	ft_printf("n: %i\n", n);
	n = printf("\0");
	ft_printf("n: %i\n", n);
	n = ft_printf("\0");
	ft_printf("n: %i\n", n);

	n = printf("%c%s%p%d%i%u%x%X%%");
	ft_printf("n: %i\n", n);
	n = ft_printf("%c%s%p%d%i%u%x%X%%");
	ft_printf("n: %i\n", n);
	ft_printf("n: %i\n", n);

	printf("<-- test printf --|\n");
	printf("*** main test finished ***\n");
}
