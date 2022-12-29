/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 20:35:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"

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
	printf("<-- test printf --|\n");

	// printf("|-- test list_func -->\n");
	// t_func	*list_func;

	// list_func = ft_create_list_func();
	// ft_list_func_print(list_func);
	// ft_list_func_print(list_func);
	// ft_list_func_clear(&list_func);
	// ft_list_func_print(list_func);
	// ft_list_func_print(list_func);
	// printf("<-- test list_func --|\n");
	printf("*** main test finished ***\n");
}
