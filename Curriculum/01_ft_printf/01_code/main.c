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
	// printf("|-- test printf -->\n");
	// // ft_printf("c%cs%sp%pd%di%iu%ux%xX%X%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// // ft_printf("%cc%ss%pp%dd%ii%uu%xx%XX%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);

	// int		n;

	// n = 0;
	// n = ft_printf("-->K<--\n-->%c  %c<--", 'K');
	// write(1, "\n", 1);
	// n = ft_printf("-->Keki<--\n-->%s<--", "Keki");
	// write(1, "\n", 1);
	// n = ft_printf("-->%<--\n-->%%<--", '%');
	// write(1, "\n", 1);
	// n = ft_printf("-->123<--\n-->%i<--", 123);
	// write(1, "\n", 1);
	// printf("<-- test printf --|\n");

	printf("|-- test list_func -->\n");
	t_func	*list_func;

	list_func = ft_create_list_func();
	ft_list_func_print(list_func);
	ft_list_func_print(list_func);
	ft_list_func_clear(&list_func);
	ft_list_func_print(list_func);
	ft_list_func_print(list_func);
	printf("<-- test list_func --|\n");

	printf("*** main test finished ***\n");
}
