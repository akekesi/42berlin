/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:25:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 02:39:20 by akekesi          ###   ########.fr       */
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

	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;
	// printf("|-- s -->\n");
	// n = ft_printf("-->%.s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%.s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.0s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%.0s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.3s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%.3s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.7s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%.7s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%1.7s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%1.7s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.13s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%7.13s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.13s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%-7.13s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+-7.13s<--\n", "abcde"); // <-- s (error: + used)
	// n___ = printf("-->%+-7.13s<--\n", "abcde"); // <-- s (error: + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.13s<--\n", "abcde"); // <-- s (error: 0 used)
	// n___ = printf("-->%0-7.13s<--\n", "abcde"); // <-- s (error: 0 used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% s<--\n", "abcde"); // <-- s (error: space used)
	// n___ = printf("-->% s<--\n", "abcde"); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% 7.13s<--\n", "abcde"); // <-- s (error: space used)
	// n___ = printf("-->% 7.13s<--\n", "abcde"); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#s<--\n", "abcde"); // <-- s (error: # used)
	// n___ = printf("-->%#s<--\n", "abcde"); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.13s<--\n", "abcde"); // <-- s (error: # used)
	// n___ = printf("-->%#7.13s<--\n", "abcde"); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%.s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.0s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%.0s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.3s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%.3s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.7s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%.7s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%1.7s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%1.7s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.13s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%7.13s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.13s<--\n", NULL); // <-- s (error: 'void *' used)
	// n___ = printf("-->%-7.13s<--\n", NULL); // <-- s (error: 'void *' used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+-7.13s<--\n", NULL); // <-- s (error: 'void *' and + used)
	// n___ = printf("-->%+-7.13s<--\n", NULL); // <-- s (error: 'void *' and + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.13s<--\n", NULL); // <-- s (error: 'void *' and 0 used)
	// n___ = printf("-->%0-7.13s<--\n", NULL); // <-- s (error: 'void *' and 0 used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% s<--\n", NULL); // <-- s (error: 'void *' and space used)
	// n___ = printf("-->% s<--\n", NULL); // <-- s (error: 'void *' and space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% 7.13s<--\n", NULL); // <-- s (error: 'void *' and space used)
	// n___ = printf("-->% 7.13s<--\n", NULL); // <-- s (error: 'void *' and space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#s<--\n", NULL); // <-- s (error: 'void *' and # used)
	// n___ = printf("-->%#s<--\n", NULL); // <-- s (error: 'void *' and # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.13s<--\n", NULL); // <-- s (error: 'void *' and # used)
	// n___ = printf("-->%#7.13s<--\n", NULL); // <-- s (error: 'void *' and # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.s<--\n", 0); // <-- s
	// n___ = printf("-->%.s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.0s<--\n", 0); // <-- s
	// n___ = printf("-->%.0s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.3s<--\n", 0); // <-- s
	// n___ = printf("-->%.3s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.7s<--\n", 0); // <-- s
	// n___ = printf("-->%.7s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%1.7s<--\n", 0); // <-- s
	// n___ = printf("-->%1.7s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.13s<--\n", 0); // <-- s
	// n___ = printf("-->%7.13s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.13s<--\n", 0); // <-- s
	// n___ = printf("-->%-7.13s<--\n", 0); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+-7.13s<--\n", 0); // <-- s (error: + used)
	// n___ = printf("-->%+-7.13s<--\n", 0); // <-- s (error: + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.13s<--\n", 0); // <-- s (error: 0 used)
	// n___ = printf("-->%0-7.13s<--\n", 0); // <-- s (error: 0 used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% s<--\n", 0); // <-- s (error: space used)
	// n___ = printf("-->% s<--\n", 0); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% 7.13s<--\n", 0); // <-- s (error: space used)
	// n___ = printf("-->% 7.13s<--\n", 0); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#s<--\n", 0); // <-- s (error: # used)
	// n___ = printf("-->%#s<--\n", 0); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.13s<--\n", 0); // <-- s (error: # used)
	// n___ = printf("-->%#7.13s<--\n", 0); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.s<--\n", ""); // <-- s
	// n___ = printf("-->%.s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.0s<--\n", ""); // <-- s
	// n___ = printf("-->%.0s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.3s<--\n", ""); // <-- s
	// n___ = printf("-->%.3s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.7s<--\n", ""); // <-- s
	// n___ = printf("-->%.7s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%1.7s<--\n", ""); // <-- s
	// n___ = printf("-->%1.7s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.13s<--\n", ""); // <-- s
	// n___ = printf("-->%7.13s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.13s<--\n", ""); // <-- s
	// n___ = printf("-->%-7.13s<--\n", ""); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+-7.13s<--\n", ""); // <-- s (error: + used)
	// n___ = printf("-->%+-7.13s<--\n", ""); // <-- s (error: + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.13s<--\n", ""); // <-- s (error: 0 used)
	// n___ = printf("-->%0-7.13s<--\n", ""); // <-- s (error: 0 used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% s<--\n", ""); // <-- s (error: space used)
	// n___ = printf("-->% s<--\n", ""); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% 7.13s<--\n", ""); // <-- s (error: space used)
	// n___ = printf("-->% 7.13s<--\n", ""); // <-- s (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#s<--\n", ""); // <-- s (error: # used)
	// n___ = printf("-->%#s<--\n", ""); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.13s<--\n", ""); // <-- s (error: # used)
	// n___ = printf("-->%#7.13s<--\n", ""); // <-- s (error: # used)
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- s --|\n");
	printf("<-- TEST --|\n");

	// int	n;
	// int	n___;
	// // int	arg;

	// n = 0;
	// n___ = 0;

	// // arg = 17;
	// // n = ft_printf("%-8.145u%000*.53x%34.30u%0079.d", 1, 1, 1, 1);
	// // n___ = printf("%-8.145u%000*.53x%34.30u%0079.d", 1, 1, 1, 1);
	// n = ft_printf("-->%+13.11d<--\n", 12345);
	// n___ = printf("-->%+13.11d<--\n", 12345);
	// if (!test_check(n, n___))
	// 	return (0);

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
