/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:25:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 19:16:32 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	main(void)
{
	printf("|-- TEST -->\n");
	printf("|-- recognition -->\n");
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	n = ft_printf("-->c%cs%sp%pd%di%iu%ux%xX%X%%% %5%<--\n", 48, "1", 2, 3, 4, 5, 6, 7);
	n___ = printf("-->c%cs%sp%pd%di%iu%ux%xX%X%%% %5%<--\n", 48, "1", 2, 3, 4, 5, 6, 7);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%cc%ss%pp%dd%ii%uu%xx%XX%%% %5%<--\n", 48, "1", 2, 3, 4, 5, 6, 7);
	n___ = printf("-->%cc%ss%pp%dd%ii%uu%xx%XX%%% %5%<--\n", 48, "1", 2, 3, 4, 5, 6, 7);
	if (!test_check(n, n___))
		return (0);
	printf("<-- recognition --|\n");

	printf("|-- type -->\n");
	test_printf_c();
	test_printf_s();
	test_printf_x();
	test_printf_x_();
	test_printf_p();
	test_printf_i();
	test_printf_d();
	test_printf_u();
	printf("<-- type --|\n");

	printf("|-- get -->\n");
	printf("-->%s<--\n", ft_get_types());
	printf("-->%s<--\n", ft_get_flags());
	printf("-->%s<--\n", ft_get_null('s'));
	printf("-->%s<--\n", ft_get_null('p'));
	printf("-->%s<--\n", ft_get_null('?'));
	printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'x', 0));
	printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'X', 0));
	printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', '+'));
	printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', ' '));
	printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', 0));
	printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'x', 0));
	printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'X', 0));
	printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', '+'));
	printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', ' '));
	printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', 0));
	printf("<-- get --|\n");
	printf("<-- TEST --|\n");
	return (1);
}
