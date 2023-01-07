/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 14:48:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_u(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- u -->\n");
	n = ft_printf("-->%.0u<--\n", 0); // <-- u
	n___ = printf("-->%.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.02u<--\n", 0); // <-- u
	n___ = printf("-->%.02u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%60.169u<--\n", -537953928); // <-- u
	n___ = printf("-->%60.169u<--\n", -537953928); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.9u<--\n", 0); // <-- u
	n___ = printf("-->%13.9u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11u<--\n", 0); // <-- u
	n___ = printf("-->%13.11u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11u<--\n", 42); // <-- u
	n___ = printf("-->%13.11u<--\n", 42); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11u<--\n", 0); // <-- u
	n___ = printf("-->%13.11u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+13.11u<--\n", -42); // <-- u
	n___ = printf("-->%+13.11u<--\n", -42); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+5.4u<--\n", -83); // <-- u
	n___ = printf("-->%+5.4u<--\n", -83); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.9u<--\n", -67943619); // <-- u
	n___ = printf("-->%13.9u<--\n", -67943619); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.7u<--\n", -67943619); // <-- u
	n___ = printf("-->%13.7u<--\n", -67943619); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-9.6u<--\n", -75); // <-- u
	n___ = printf("-->%-9.6u<--\n", -75); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%9.38u<--\n", 0); // <-- u
	n___ = printf("-->%9.38u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-8.4u<--\n", 0); // <-- u
	n___ = printf("-->%-8.4u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%2.2u<--\n", 0); // <-- u
	n___ = printf("-->%2.2u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0 10u<--\n", 0); // <-- u
	n___ = printf("-->%0 10u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10u<--\n", 0); // <-- u
	n___ = printf("-->%0+10u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10u<--\n", 42); // <-- u
	n___ = printf("-->%0+10u<--\n", 42); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.8u<--\n", 42); // <-- u
	n___ = printf("-->%0+10.8u<--\n", 42); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.0u<--\n", 0); // <-- u
	n___ = printf("-->%0+10.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", 0); // <-- u
	n___ = printf("-->%.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", 34); // <-- u
	n___ = printf("-->%.u<--\n", 34); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", -1); // <-- u
	n___ = printf("-->%.u<--\n", -1); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+.u<--\n", 0); // <-- u
	n___ = printf("-->%+.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+5.u<--\n", 0); // <-- u
	n___ = printf("-->%+5.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%01.u<--\n", 0); // <-- u
	n___ = printf("-->%01.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.0u<--\n", 0); // <-- u
	n___ = printf("-->%0+10.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.u<--\n", 5); // <-- u
	n___ = printf("-->%05.u<--\n", 5); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.2u<--\n", 123); // <-- u
	n___ = printf("-->%.2u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", NULL); // <-- u
	n___ = printf("-->%.u<--\n", NULL); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", 0); // <-- u
	n___ = printf("-->%.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0u<--\n", 0); // <-- u
	n___ = printf("-->%.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%5.0u<--\n", 0); // <-- u
	n___ = printf("-->%5.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+.2u<--\n", 123); // <-- u
	n___ = printf("-->%+.2u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.2u<--\n", 123); // <-- u
	n___ = printf("-->%.2u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", NULL); // <-- u
	n___ = printf("-->%.u<--\n", NULL); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.u<--\n", 0); // <-- u
	n___ = printf("-->%.u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0u<--\n", 0); // <-- u
	n___ = printf("-->%.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%5.0u<--\n", 0); // <-- u
	n___ = printf("-->%5.0u<--\n", 0); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%u<--\n", 123); // <-- u
	n___ = printf("-->%u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% u<--\n", 123); // <-- u (error: space)
	n___ = printf("-->% u<--\n", 123); // <-- u (error: space)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+u<--\n", 123); // <-- u (error: +)
	n___ = printf("-->%+u<--\n", 123); // <-- u (error: +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ u<--\n", 123); // <-- u (error: space and  +)
	n___ = printf("-->%+ u<--\n", 123); // <-- u (error: space and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ u<--\n", 123); // <-- u (error: #, space and  +)
	n___ = printf("-->%#+ u<--\n", 123); // <-- u (error: #, space and  +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05u<--\n", 123); // <-- u
	n___ = printf("-->%05u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5u<--\n", 123); // <-- u
	n___ = printf("-->%.5u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05u<--\n", 123); // <-- u (error: 0)
	n___ = printf("-->%-05u<--\n", 123); // <-- u (error: 0)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5u<--\n", 123); // <-- u
	n___ = printf("-->%-.5u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5u<--\n", 123); // <-- u
	n___ = printf("-->%7.5u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5u<--\n", 123); // <-- u
	n___ = printf("-->%-7.5u<--\n", 123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5u<--\n", 123); // <-- u (error: +)
	n___ = printf("-->%-+7.5u<--\n", 123); // <-- u (error: +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5u<--\n", 123); // <-- u (error: space)
	n___ = printf("-->%- 7.5u<--\n", 123); // <-- u (error: space)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5u<--\n", 123); // <-- u (error: +, 0, - and .)
	n___ = printf("-->%-+07.5u<--\n", 123); // <-- u (error: +, 0, - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5u<--\n", 123); // <-- u (error: space, 0, - and .)
	n___ = printf("-->%- 07.5u<--\n", 123); // <-- u (error: space, 0, - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6u<--\n", 123); // <-- u (error: space, 0, -, + and .)
	n___ = printf("-->%- +08.6u<--\n", 123); // <-- u (error: space, 0, -, + and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.u<--\n", 123); // <-- u (error: 0 with .)
	n___ = printf("-->%05.u<--\n", 123); // <-- u (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%u<--\n", -123); // <-- u
	n___ = printf("-->%u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% u<--\n", -123); // <-- u (error: space)
	n___ = printf("-->% u<--\n", -123); // <-- u (error: space)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+u<--\n", -123); // <-- u (error: +)
	n___ = printf("-->%+u<--\n", -123); // <-- u (error: +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ u<--\n", -123); // <-- u (error: space and  +)
	n___ = printf("-->%+ u<--\n", -123); // <-- u (error: space and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ u<--\n", -123); // <-- u (error: #, space and  +)
	n___ = printf("-->%#+ u<--\n", -123); // <-- u (error: #, space and  +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05u<--\n", -123); // <-- u
	n___ = printf("-->%05u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5u<--\n", -123); // <-- u
	n___ = printf("-->%.5u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05u<--\n", -123); // <-- u (error: 0)
	n___ = printf("-->%-05u<--\n", -123); // <-- u (error: 0)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5u<--\n", -123); // <-- u
	n___ = printf("-->%-.5u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5u<--\n", -123); // <-- u
	n___ = printf("-->%7.5u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5u<--\n", -123); // <-- u
	n___ = printf("-->%-7.5u<--\n", -123); // <-- u
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5u<--\n", -123); // <-- u (error: +)
	n___ = printf("-->%-+7.5u<--\n", -123); // <-- u (error: +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5u<--\n", -123); // <-- u (error: space)
	n___ = printf("-->%- 7.5u<--\n", -123); // <-- u (error: space)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5u<--\n", -123); // <-- u (error: +, 0, - and .)
	n___ = printf("-->%-+07.5u<--\n", -123); // <-- u (error: +, 0, - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5u<--\n", -123); // <-- u (error: space, 0, - and .)
	n___ = printf("-->%- 07.5u<--\n", -123); // <-- u (error: space, 0, - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6u<--\n", -123); // <-- u (error: space, 0, -, + and .)
	n___ = printf("-->%- +08.6u<--\n", -123); // <-- u (error: space, 0, -, + and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.u<--\n", -123); // <-- u (error: 0 with .)
	n___ = printf("-->%05.u<--\n", -123); // <-- u (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	printf("<-- u --|\n");
	return (1);
}
