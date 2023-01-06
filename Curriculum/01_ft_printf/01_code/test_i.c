/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/06 16:08:54 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	test_printf_i(void)
{
	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;

	printf("|-- i -->\n");
	n = ft_printf("-->%i<--\n", 123); // <-- i
	n___ = printf("-->%i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% i<--\n", 123); // <-- i
	n___ = printf("-->% i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+i<--\n", 123); // <-- i
	n___ = printf("-->%+i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ i<--\n", 123); // <-- i (error: space with +)
	n___ = printf("-->%+ i<--\n", 123); // <-- i (error: space with +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ i<--\n", 123); // <-- i (error: #)
	n___ = printf("-->%#+ i<--\n", 123); // <-- i (error: #)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05i<--\n", 123); // <-- i
	n___ = printf("-->%05i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5i<--\n", 123); // <-- i
	n___ = printf("-->%.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05i<--\n", 123); // <-- i (error: 0 with -)
	n___ = printf("-->%-05i<--\n", 123); // <-- i (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5i<--\n", 123); // <-- i
	n___ = printf("-->%-.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5i<--\n", 123); // <-- i
	n___ = printf("-->%7.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5i<--\n", 123); // <-- i
	n___ = printf("-->%-7.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5i<--\n", 123); // <-- i
	n___ = printf("-->%-+7.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5i<--\n", 123); // <-- i
	n___ = printf("-->%- 7.5i<--\n", 123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5i<--\n", 123); // <-- i (error: 0 with . and -)
	n___ = printf("-->%-+07.5i<--\n", 123); // <-- i (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5i<--\n", 123); // <-- i (error: 0 with . and -)
	n___ = printf("-->%- 07.5i<--\n", 123); // <-- i (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6i<--\n", 123); // <-- i (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6i<--\n", 123); // <-- i (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.i<--\n", 123); // <-- i (error: 0 with .)
	n___ = printf("-->%05.i<--\n", 123); // <-- i (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%i<--\n", -123); // <-- i
	n___ = printf("-->%i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->% i<--\n", -123); // <-- i
	n___ = printf("-->% i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+i<--\n", -123); // <-- i
	n___ = printf("-->%+i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%+ i<--\n", -123); // <-- i (error: space with +)
	n___ = printf("-->%+ i<--\n", -123); // <-- i (error: space with +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%#+ i<--\n", -123); // <-- i (error: #)
	n___ = printf("-->%#+ i<--\n", -123); // <-- i (error: #)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05i<--\n", -123); // <-- i
	n___ = printf("-->%05i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%.5i<--\n", -123); // <-- i
	n___ = printf("-->%.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-05i<--\n", -123); // <-- i (error: 0 with -)
	n___ = printf("-->%-05i<--\n", -123); // <-- i (error: 0 with -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-.5i<--\n", -123); // <-- i
	n___ = printf("-->%-.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%7.5i<--\n", -123); // <-- i
	n___ = printf("-->%7.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-7.5i<--\n", -123); // <-- i
	n___ = printf("-->%-7.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+7.5i<--\n", -123); // <-- i
	n___ = printf("-->%-+7.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 7.5i<--\n", -123); // <-- i
	n___ = printf("-->%- 7.5i<--\n", -123); // <-- i
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%-+07.5i<--\n", -123); // <-- i (error: 0 with . and -)
	n___ = printf("-->%-+07.5i<--\n", -123); // <-- i (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- 07.5i<--\n", -123); // <-- i (error: 0 with . and -)
	n___ = printf("-->%- 07.5i<--\n", -123); // <-- i (error: 0 with . and -)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6i<--\n", -123); // <-- i (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6i<--\n", -123); // <-- i (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%05.i<--\n", -123); // <-- i (error: 0 with .)
	n___ = printf("-->%05.i<--\n", -123); // <-- i (error: 0 with .)
	if (!test_check(n, n___))
		return (0);

	n = ft_printf("-->%- +08.6i<--\n", 0); // <-- i (error: 0 with ., - and +)
	n___ = printf("-->%- +08.6i<--\n", 0); // <-- i (error: 0 with ., - and +)
	if (!test_check(n, n___))
		return (0);
	printf("<-- i --|\n");
	return (1);
}
