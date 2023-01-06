/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/06 16:08:54 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_p(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- p -->\n");
	n = ft_printf("-->%7p<--\n", 171); // <-- p
	n___ = printf("-->%7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% 7p<--\n", 171); // <-- p
	n___ = printf("-->% 7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+7p<--\n", 171); // <-- p
	n___ = printf("-->%+7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7p<--\n", 171); // <-- p
	n___ = printf("-->%-7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7p<--\n", 171); // <-- p
	n___ = printf("-->%- 7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7p<--\n", 171); // <-- p
	n___ = printf("-->%-+7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07p<--\n", 171); // <-- p
	n___ = printf("-->%07p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0 7p<--\n", 171); // <-- p
	n___ = printf("-->%0 7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+7p<--\n", 171); // <-- p
	n___ = printf("-->%0+7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-7p<--\n", 171); // <-- p
	n___ = printf("-->%0-7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0- 7p<--\n", 171); // <-- p
	n___ = printf("-->%0- 7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-+7p<--\n", 171); // <-- p
	n___ = printf("-->%0-+7p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07.6p<--\n", 171); // <-- p
	n___ = printf("-->%07.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0 7.6p<--\n", 171); // <-- p
	n___ = printf("-->%0 7.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+7.6p<--\n", 171); // <-- p
	n___ = printf("-->%0+7.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-7.6p<--\n", 171); // <-- p
	n___ = printf("-->%0-7.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0- 7.6p<--\n", 171); // <-- p
	n___ = printf("-->%0- 7.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-+7.6p<--\n", 171); // <-- p
	n___ = printf("-->%0-+7.6p<--\n", 171); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-+8.7p<--\n", 0); // <-- p
	n___ = printf("-->%0-+8.7p<--\n", 0); // <-- p
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+8.7p<--\n", 0); // <-- p
	n___ = printf("-->%0+8.7p<--\n", 0); // <-- p
	if (!test_check(n, n___))
		return (0);

	printf("<-- p --|\n");
	return (1);
}
