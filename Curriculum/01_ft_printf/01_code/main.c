/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:25:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 00:11:06 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

/*
const char *str in printf cast char * --> delete everywhere const char
without t, in func just check if types is reached --> kevesebb arg in pad func es lehetne a charra is hasznalni, ha atadjuk, az argstr hosszat (char \0 is jo lesz)
-ft_int_in_str(str, t)
-ft_char_in_str_n('-', str, t)
*/

int	main(void)
{
	printf("|-- TEST -->\n");

	// ???
	// int	i;
	// int	*flags;
	// char	str[] = "+-# 0123.0456";

	// flags = ft_flags_in_str(str, ft_str_len(str));
	// i = 0;
	// while (i < 8)
	// {
	// 	printf("--> %d. %d\n", i, flags[i]);
	// 	i++;
	// }
	// ???

	int	n;
	int	n___;
	int	arg;

	n = 0;
	n___ = 0;

	arg = 17;
	n = ft_printf("-->%04d<--\n", -14);
	n___ = printf("-->%04d<--\n", -14);
	if (!test_check(n, n___))
		return (0);

	// n = ft_printf("-->%#+ - 012.013sXXX%03.2-sXXX%-05.3s<--\n", "ABC", "abcde", "12345");

	// n = ft_printf("-->%.02d<--\n", 123);
	// n___ = printf("-->%14.04d<--\n", 123);
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-4.02s<--\n", "abc");
	// n___ = printf("-->%-4.02s<--\n", "abc");
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-4.2s<--\n", NULL);
	// n___ = printf("-->%-4.2s<--\n", NULL);
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%3s<--\n", "\0");
	// n___ = printf("-->%3s<--\n", "\0");
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%5s<--\n", "123");
	// n___ = printf("-->%5s<--\n", "123");
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-5s<--\n", "123");
	// n___ = printf("-->%-5s<--\n", "123");
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%c_%c<--\n", 0, '\0');
	// n___ = printf("-->%c_%c<--\n", 0, '\0');
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%3c %c %c %c %-3c<--\n",  '0', 0, '\0', ' ', '1');
	// n___ = printf("-->%3c %c %c %c %-3c<--\n",  '0', 0, '\0', ' ', '1');

	// write(1, "A\0A", 3);

	// n = ft_printf("-->%3c<--\n", 'X');
	// n___ = printf("-->%3c<--\n", 'X');
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-3c<--\n", 'X');
	// n___ = printf("-->%-3c<--\n", 'X');
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-0123456789.# +c%%_%_%_%%%<--\n", 'X');
	// n___ = printf("-->X%%_%%_%%_%%%%<--\n");
	// if (!test_check(n, n___))
	// 	return (0);

	// printf("-->%s<--\n", ft_get_types());
	// printf("-->%s<--\n", ft_get_flags());
	// printf("-->%s<--\n", ft_get_null('s'));
	// printf("-->%s<--\n", ft_get_null('p'));
	// printf("-->%s<--\n", ft_get_null('?'));
	return (1);
}
