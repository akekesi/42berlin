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
	// ft_printf("c%cs%sp%pd%di%iu%ux%xX%X%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// ft_printf("%cc%ss%pp%dd%ii%uu%xx%XX%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	ft_printf("a%ic%id", 1, 2);
	printf("<-- test printf --|\n");

	printf("|-- test list_func -->\n");
	t_func	**list_func;

	list_func = ft_create_list_func();
	ft_list_func_print(*list_func);
	// ft_list_func_print(*list_func); // tmp-vel jo, amugy nem ???
	// printf("*list_func in main after clear: %p <-- something trash?\n", *list_func); // ha ez itt van, akkor segmentation fault ??
	// ft_list_func_clear(list_func);
	printf("list_func in main after clear:  %p\n", list_func);
	printf("*list_func in main after clear: %p <-- something trash?\n", *list_func);

	printf("!!! list_func: del and clear are needed !!!\n");
	printf("<-- test list_func --|\n");

	printf("*** main test finished ***\n");
}
