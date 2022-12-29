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
	printf("|-- test list_func -->\n");
	t_func	**list_func;

	list_func = ft_create_list_func();

	ft_list_func_clear(list_func);
	printf("list_func in main:   %p\n", list_func);
	printf("*list_func in main:  %p <-- Not NULL?\n", *list_func);

	printf("!!! list_func: del and clear are needed !!!\n");
	printf("<-- test list_func --|\n");
	// ft_printf("c%cs%sp%pd%di%iu%ux%xX%X%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// ft_printf("%cc%ss%pp%dd%ii%uu%xx%XX%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// ft_printf("a%ic%id", 1, 2);
	printf("*** main test finished ***\n");
}
