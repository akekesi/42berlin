/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/06 18:12:17 by akekesi          ###   ########.fr       */
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
	n = ft_printf("-->%.2i<--\n", 123); // <-- i
	n___ = printf("-->%.2i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.i<--\n", NULL); // <-- i
	n___ = printf("-->%.i<--\n", NULL); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.i<--\n", 0); // <-- i
	n___ = printf("-->%.i<--\n", 0); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.0i<--\n", 0); // <-- i
	n___ = printf("-->%.0i<--\n", 0); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%5.0i<--\n", 0); // <-- i
	n___ = printf("-->%5.0i<--\n", 0); // <-- i
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
