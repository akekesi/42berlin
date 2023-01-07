/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 14:34:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_x_(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- X -->\n");
	n = ft_printf("-->%#X<--\n", 0); // <-- X
	n___ = printf("-->%#X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.X<--\n", 0); // <-- X
	n___ = printf("-->%.X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.X<--\n", 34); // <-- X
	n___ = printf("-->%.X<--\n", 34); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.X<--\n", -1); // <-- X
	n___ = printf("-->%.X<--\n", -1); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+.X<--\n", 0); // <-- X
	n___ = printf("-->%+.X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+.X<--\n", 42); // <-- X
	n___ = printf("-->%+.X<--\n", 42); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% .X<--\n", 42); // <-- X
	n___ = printf("-->% .X<--\n", 42); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+5.X<--\n", 0); // <-- X
	n___ = printf("-->%+5.X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%01.X<--\n", 0); // <-- X
	n___ = printf("-->%01.X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.X<--\n", 5); // <-- X
	n___ = printf("-->%05.X<--\n", 5); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#14.10X<--\n", -42); // <-- X
	n___ = printf("-->%-#14.10X<--\n", -42); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#10X<--\n", 25186972); // <-- X
	n___ = printf("-->%0#10X<--\n", 25186972); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#6X<--\n", 0); // <-- X
	n___ = printf("-->%0#6X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%X<--\n", 171); // <-- X
	n___ = printf("-->%X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1X<--\n", 171); // <-- X
	n___ = printf("-->%.1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#.1X<--\n", 171); // <-- X
	n___ = printf("-->%#.1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%X<--\n", 0); // <-- X
	n___ = printf("-->%X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.X<--\n", 0); // <-- X
	n___ = printf("-->%.X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0X<--\n", 0); // <-- X
	n___ = printf("-->%.0X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%X<--\n", 171); // <-- X
	n___ = printf("-->%X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#X<--\n", 171); // <-- X
	n___ = printf("-->%#X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% X<--\n", 171); // <-- X (error: space used)
	n___ = printf("-->% X<--\n", 171); // <-- X (error: space used)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+X<--\n", 171); // <-- X (error: + used)
	n___ = printf("-->%+X<--\n", 171); // <-- X (error: + used)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%3X<--\n", 171); // <-- X
	n___ = printf("-->%3X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#1X<--\n", 171); // <-- X
	n___ = printf("-->%#1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#3X<--\n", 171); // <-- X
	n___ = printf("-->%#3X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#5X<--\n", 171); // <-- X
	n___ = printf("-->%#5X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-3X<--\n", 171); // <-- X
	n___ = printf("-->%-3X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#1X<--\n", 171); // <-- X
	n___ = printf("-->%-#1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#3X<--\n", 171); // <-- X
	n___ = printf("-->%-#3X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#5X<--\n", 171); // <-- X
	n___ = printf("-->%-#5X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%03X<--\n", 171); // <-- X
	n___ = printf("-->%03X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#1X<--\n", 171); // <-- X
	n___ = printf("-->%0#1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#3X<--\n", 171); // <-- X
	n___ = printf("-->%0#3X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#5X<--\n", 171); // <-- X
	n___ = printf("-->%0#5X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#7X<--\n", 171); // <-- X
	n___ = printf("-->%0#7X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7X<--\n", 171); // <-- X
	n___ = printf("-->%-#7X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#05X<--\n", 171); // <-- X (error: 0 with -)
	n___ = printf("-->%-#05X<--\n", 171); // <-- X (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#09.X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%#09.X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#09.X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%-#09.X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#09.3X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%#09.3X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#09.3X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%-#09.3X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.X<--\n", 171);
	n___ = printf("-->%.X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1X<--\n", 171);
	n___ = printf("-->%.1X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.1X<--\n", 171);
	n___ = printf("-->%7.1X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.4X<--\n", 171);
	n___ = printf("-->%7.4X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#7.4X<--\n", 171);
	n___ = printf("-->%#7.4X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.4X<--\n", 171);
	n___ = printf("-->%-7.4X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.4X<--\n", 171);
	n___ = printf("-->%-#7.4X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.1X<--\n", 171);
	n___ = printf("-->%-#7.1X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#3.5X<--\n", 171);
	n___ = printf("-->%-#3.5X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5X<--\n", 171);
	n___ = printf("-->%-.5X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#1.1X<--\n", 171);
	n___ = printf("-->%-#1.1X<--\n", 171);
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0.X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%0.X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0.1X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%0.1X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07.1X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%07.1X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%07.4X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%07.4X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#7.4X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%0#7.4X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-#7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#7.1X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-#7.1X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#3.5X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-#3.5X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-.5X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-.5X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#1.1X<--\n", 171); // <-- X (error: 0 with - and .)
	n___ = printf("-->%0-#1.1X<--\n", 171); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#01.5X<--\n", 171); // <-- X (error: 0 with .)
	n___ = printf("-->%#01.5X<--\n", 171); // <-- X (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-3X<--\n", 171); // <-- X (error: 0 with -)
	n___ = printf("-->%0-3X<--\n", 171); // <-- X (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#1X<--\n", 171); // <-- X (error: 0 with -)
	n___ = printf("-->%0-#1X<--\n", 171); // <-- X (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#3X<--\n", 171); // <-- X (error: 0 with -)
	n___ = printf("-->%0-#3X<--\n", 171); // <-- X (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0-#5X<--\n", 171); // <-- X (error: 0 with -)
	n___ = printf("-->%0-#5X<--\n", 171); // <-- X (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05X<--\n", 171); // <-- X
	n___ = printf("-->%05X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0#5X<--\n", 171); // <-- X
	n___ = printf("-->%0#5X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.1X<--\n", 171); // <-- X
	n___ = printf("-->%.1X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5X<--\n", 171); // <-- X
	n___ = printf("-->%.5X<--\n", 171); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%X<--\n", 0); // <-- X
	n___ = printf("-->%X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#X<--\n", 0); // <-- X
	n___ = printf("-->%#X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#3X<--\n", 0); // <-- X
	n___ = printf("-->%#3X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#7.6X<--\n", 0); // <-- X
	n___ = printf("-->%#7.6X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-#7.6X<--\n", 0); // <-- X
	n___ = printf("-->%-#7.6X<--\n", 0); // <-- X
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-0#7.6X<--\n", 0); // <-- X (error: 0 with - and .)
	n___ = printf("-->%-0#7.6X<--\n", 0); // <-- X (error: 0 with - and .)
	if (!test_check(n, n___))
		return (0);

	printf("<-- X --|\n");
	return (1);
}
