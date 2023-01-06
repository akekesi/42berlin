/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/06 18:51:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_x(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- x -->\n");
	n = ft_printf("-->%x<--\n", 171); // <-- x
	n___ = printf("-->%x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1x<--\n", 171); // <-- x
	n___ = printf("-->%.1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#.1x<--\n", 171); // <-- x
	n___ = printf("-->%#.1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%x<--\n", 0); // <-- x
	n___ = printf("-->%x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.x<--\n", 0); // <-- x
	n___ = printf("-->%.x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0x<--\n", 0); // <-- x
	n___ = printf("-->%.0x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%x<--\n", 171); // <-- x
	n___ = printf("-->%x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#x<--\n", 171); // <-- x
	n___ = printf("-->%#x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% x<--\n", 171); // <-- x (error: space used)
	n___ = printf("-->% x<--\n", 171); // <-- x (error: space used)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+x<--\n", 171); // <-- x (error: + used)
	n___ = printf("-->%+x<--\n", 171); // <-- x (error: + used)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%3x<--\n", 171); // <-- x
	n___ = printf("-->%3x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#1x<--\n", 171); // <-- x
	n___ = printf("-->%#1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#3x<--\n", 171); // <-- x
	n___ = printf("-->%#3x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#5x<--\n", 171); // <-- x
	n___ = printf("-->%#5x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-3x<--\n", 171); // <-- x
	n___ = printf("-->%-3x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#1x<--\n", 171); // <-- x
	n___ = printf("-->%-#1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#3x<--\n", 171); // <-- x
	n___ = printf("-->%-#3x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#5x<--\n", 171); // <-- x
	n___ = printf("-->%-#5x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%03x<--\n", 171); // <-- x
	n___ = printf("-->%03x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#1x<--\n", 171); // <-- x
	n___ = printf("-->%0#1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#3x<--\n", 171); // <-- x
	n___ = printf("-->%0#3x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#5x<--\n", 171); // <-- x
	n___ = printf("-->%0#5x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#7x<--\n", 171); // <-- x
	n___ = printf("-->%0#7x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7x<--\n", 171); // <-- x
	n___ = printf("-->%-#7x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#05x<--\n", 171); // <-- x (error: 0 with -)
	n___ = printf("-->%-#05x<--\n", 171); // <-- x (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#09.x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%#09.x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#09.x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%-#09.x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#09.3x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%#09.3x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#09.3x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%-#09.3x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.x<--\n", 171);
	n___ = printf("-->%.x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1x<--\n", 171);
	n___ = printf("-->%.1x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.1x<--\n", 171);
	n___ = printf("-->%7.1x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.4x<--\n", 171);
	n___ = printf("-->%7.4x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#7.4x<--\n", 171);
	n___ = printf("-->%#7.4x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.4x<--\n", 171);
	n___ = printf("-->%-7.4x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.4x<--\n", 171);
	n___ = printf("-->%-#7.4x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.1x<--\n", 171);
	n___ = printf("-->%-#7.1x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#3.5x<--\n", 171);
	n___ = printf("-->%-#3.5x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5x<--\n", 171);
	n___ = printf("-->%-.5x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#1.1x<--\n", 171);
	n___ = printf("-->%-#1.1x<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0.x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%0.x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0.1x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%0.1x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07.1x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%07.1x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07.4x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%07.4x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#7.4x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%0#7.4x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-#7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#7.1x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-#7.1x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#3.5x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-#3.5x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-.5x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-.5x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#1.1x<--\n", 171); // <-- x (error: 0 with - and .)
	n___ = printf("-->%0-#1.1x<--\n", 171); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#01.5x<--\n", 171); // <-- x (error: 0 with .)
	n___ = printf("-->%#01.5x<--\n", 171); // <-- x (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-3x<--\n", 171); // <-- x (error: 0 with -)
	n___ = printf("-->%0-3x<--\n", 171); // <-- x (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#1x<--\n", 171); // <-- x (error: 0 with -)
	n___ = printf("-->%0-#1x<--\n", 171); // <-- x (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#3x<--\n", 171); // <-- x (error: 0 with -)
	n___ = printf("-->%0-#3x<--\n", 171); // <-- x (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#5x<--\n", 171); // <-- x (error: 0 with -)
	n___ = printf("-->%0-#5x<--\n", 171); // <-- x (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05x<--\n", 171); // <-- x
	n___ = printf("-->%05x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#5x<--\n", 171); // <-- x
	n___ = printf("-->%0#5x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1x<--\n", 171); // <-- x
	n___ = printf("-->%.1x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5x<--\n", 171); // <-- x
	n___ = printf("-->%.5x<--\n", 171); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%x<--\n", 0); // <-- x
	n___ = printf("-->%x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#x<--\n", 0); // <-- x
	n___ = printf("-->%#x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#3x<--\n", 0); // <-- x
	n___ = printf("-->%#3x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#7.6x<--\n", 0); // <-- x
	n___ = printf("-->%#7.6x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.6x<--\n", 0); // <-- x
	n___ = printf("-->%-#7.6x<--\n", 0); // <-- x
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-0#7.6x<--\n", 0); // <-- x (error: 0 with - and .)
	n___ = printf("-->%-0#7.6x<--\n", 0); // <-- x (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	printf("<-- x --|\n");
	return (1);
}
