/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 14:46:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_d(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- d -->\n");
	n = ft_printf("-->%.0d<--\n", 0); // <-- d
	n___ = printf("-->%.0d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.02d<--\n", 0); // <-- d
	n___ = printf("-->%.02d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%60.169d<--\n", -537953928); // <-- d
	n___ = printf("-->%60.169d<--\n", -537953928); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.9d<--\n", 0); // <-- d
	n___ = printf("-->%13.9d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11d<--\n", 0); // <-- d
	n___ = printf("-->%13.11d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11d<--\n", 42); // <-- d
	n___ = printf("-->%13.11d<--\n", 42); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.11d<--\n", 0); // <-- d
	n___ = printf("-->%13.11d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+13.11d<--\n", -42); // <-- d
	n___ = printf("-->%+13.11d<--\n", -42); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+5.4d<--\n", -83); // <-- d
	n___ = printf("-->%+5.4d<--\n", -83); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.9d<--\n", -67943619); // <-- d
	n___ = printf("-->%13.9d<--\n", -67943619); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%13.7d<--\n", -67943619); // <-- d
	n___ = printf("-->%13.7d<--\n", -67943619); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-9.6d<--\n", -75); // <-- d
	n___ = printf("-->%-9.6d<--\n", -75); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%9.38d<--\n", 0); // <-- d
	n___ = printf("-->%9.38d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-8.4d<--\n", 0); // <-- d
	n___ = printf("-->%-8.4d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%2.2d<--\n", 0); // <-- d
	n___ = printf("-->%2.2d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0 10d<--\n", 0); // <-- d
	n___ = printf("-->%0 10d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10d<--\n", 0); // <-- d
	n___ = printf("-->%0+10d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10d<--\n", 42); // <-- d
	n___ = printf("-->%0+10d<--\n", 42); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.8d<--\n", 42); // <-- d
	n___ = printf("-->%0+10.8d<--\n", 42); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.0d<--\n", 0); // <-- d
	n___ = printf("-->%0+10.0d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.d<--\n", 0); // <-- d
	n___ = printf("-->%.d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.d<--\n", 34); // <-- d
	n___ = printf("-->%.d<--\n", 34); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.d<--\n", -1); // <-- d
	n___ = printf("-->%.d<--\n", -1); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+.d<--\n", 0); // <-- d
	n___ = printf("-->%+.d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+5.d<--\n", 0); // <-- d
	n___ = printf("-->%+5.d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%01.d<--\n", 0); // <-- d
	n___ = printf("-->%01.d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%0+10.0d<--\n", 0); // <-- d
	n___ = printf("-->%0+10.0d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.d<--\n", 5); // <-- d
	n___ = printf("-->%05.d<--\n", 5); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.2d<--\n", 123); // <-- d
	n___ = printf("-->%.2d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.d<--\n", NULL); // <-- d
	n___ = printf("-->%.d<--\n", NULL); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.d<--\n", 0); // <-- d
	n___ = printf("-->%.d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0d<--\n", 0); // <-- d
	n___ = printf("-->%.0d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%5.0d<--\n", 0); // <-- d
	n___ = printf("-->%5.0d<--\n", 0); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%d<--\n", 123); // <-- d
	n___ = printf("-->%d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% d<--\n", 123); // <-- d
	n___ = printf("-->% d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+d<--\n", 123); // <-- d
	n___ = printf("-->%+d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ d<--\n", 123); // <-- d (error: space with +)
	n___ = printf("-->%+ d<--\n", 123); // <-- d (error: space with +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ d<--\n", 123); // <-- d (error: #)
	n___ = printf("-->%#+ d<--\n", 123); // <-- d (error: #)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05d<--\n", 123); // <-- d
	n___ = printf("-->%05d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5d<--\n", 123); // <-- d
	n___ = printf("-->%.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05d<--\n", 123); // <-- d (error: 0 with -)
	n___ = printf("-->%-05d<--\n", 123); // <-- d (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5d<--\n", 123); // <-- d
	n___ = printf("-->%-.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5d<--\n", 123); // <-- d
	n___ = printf("-->%7.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5d<--\n", 123); // <-- d
	n___ = printf("-->%-7.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5d<--\n", 123); // <-- d
	n___ = printf("-->%-+7.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5d<--\n", 123); // <-- d
	n___ = printf("-->%- 7.5d<--\n", 123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5d<--\n", 123); // <-- d (error: 0 with . and -)
	n___ = printf("-->%-+07.5d<--\n", 123); // <-- d (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5d<--\n", 123); // <-- d (error: 0 with . and -)
	n___ = printf("-->%- 07.5d<--\n", 123); // <-- d (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6d<--\n", 123); // <-- d (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6d<--\n", 123); // <-- d (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.d<--\n", 123); // <-- d (error: 0 with .)
	n___ = printf("-->%05.d<--\n", 123); // <-- d (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%d<--\n", -123); // <-- d
	n___ = printf("-->%d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% d<--\n", -123); // <-- d
	n___ = printf("-->% d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+d<--\n", -123); // <-- d
	n___ = printf("-->%+d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ d<--\n", -123); // <-- d (error: space with +)
	n___ = printf("-->%+ d<--\n", -123); // <-- d (error: space with +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ d<--\n", -123); // <-- d (error: #)
	n___ = printf("-->%#+ d<--\n", -123); // <-- d (error: #)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05d<--\n", -123); // <-- d
	n___ = printf("-->%05d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5d<--\n", -123); // <-- d
	n___ = printf("-->%.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05d<--\n", -123); // <-- d (error: 0 with -)
	n___ = printf("-->%-05d<--\n", -123); // <-- d (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5d<--\n", -123); // <-- d
	n___ = printf("-->%-.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5d<--\n", -123); // <-- d
	n___ = printf("-->%7.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5d<--\n", -123); // <-- d
	n___ = printf("-->%-7.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5d<--\n", -123); // <-- d
	n___ = printf("-->%-+7.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5d<--\n", -123); // <-- d
	n___ = printf("-->%- 7.5d<--\n", -123); // <-- d
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5d<--\n", -123); // <-- d (error: 0 with . and -)
	n___ = printf("-->%-+07.5d<--\n", -123); // <-- d (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5d<--\n", -123); // <-- d (error: 0 with . and -)
	n___ = printf("-->%- 07.5d<--\n", -123); // <-- d (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6d<--\n", -123); // <-- d (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6d<--\n", -123); // <-- d (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.d<--\n", -123); // <-- d (error: 0 with .)
	n___ = printf("-->%05.d<--\n", -123); // <-- d (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6d<--\n", 0); // <-- d (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6d<--\n", 0); // <-- d (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);
	printf("<-- d --|\n");
	return (1);
}
