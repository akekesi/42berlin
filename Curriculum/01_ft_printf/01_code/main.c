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
-ft_char_in_str_n('-', xtr, t)
*/

int	main(void)
{
	printf("|-- TEST -->\n");

	int	n;
	int	n___;
	
	n = 0;
	n___ = 0;
	// printf("|-- s -->\n");
	// n = ft_printf("-->%s<--\n", "abcde"); // <-- s
	// n___ = printf("-->%s<--\n", "abcde"); // <-- s
	// if (!test_check(n, n___))
	// 	return (0);
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

	// printf("|-- x -->\n");
	// n = ft_printf("-->%x<--\n", 171); // <-- x
	// n___ = printf("-->%x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#x<--\n", 171); // <-- x
	// n___ = printf("-->%#x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% x<--\n", 171); // <-- x (error: space used)
	// n___ = printf("-->% x<--\n", 171); // <-- x (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+x<--\n", 171); // <-- x (error: + used)
	// n___ = printf("-->%+x<--\n", 171); // <-- x (error: + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%3x<--\n", 171); // <-- x
	// n___ = printf("-->%3x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#1x<--\n", 171); // <-- x
	// n___ = printf("-->%#1x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#3x<--\n", 171); // <-- x
	// n___ = printf("-->%#3x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#5x<--\n", 171); // <-- x
	// n___ = printf("-->%#5x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-3x<--\n", 171); // <-- x
	// n___ = printf("-->%-3x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#1x<--\n", 171); // <-- x
	// n___ = printf("-->%-#1x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#3x<--\n", 171); // <-- x
	// n___ = printf("-->%-#3x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#5x<--\n", 171); // <-- x
	// n___ = printf("-->%-#5x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%03x<--\n", 171); // <-- x
	// n___ = printf("-->%03x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#1x<--\n", 171); // <-- x
	// n___ = printf("-->%0#1x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#3x<--\n", 171); // <-- x
	// n___ = printf("-->%0#3x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#5x<--\n", 171); // <-- x
	// n___ = printf("-->%0#5x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#7x<--\n", 171); // <-- x
	// n___ = printf("-->%0#7x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7x<--\n", 171); // <-- x
	// n___ = printf("-->%-#7x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#05x<--\n", 171); // <-- x (error: 0 with -)
	// n___ = printf("-->%-#05x<--\n", 171); // <-- x (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#09.x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%#09.x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#09.x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%-#09.x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#09.3x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%#09.3x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#09.3x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%-#09.3x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.x<--\n", 171);
	// n___ = printf("-->%.x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.1x<--\n", 171);
	// n___ = printf("-->%.1x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.1x<--\n", 171);
	// n___ = printf("-->%7.1x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.4x<--\n", 171);
	// n___ = printf("-->%7.4x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.4x<--\n", 171);
	// n___ = printf("-->%#7.4x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.4x<--\n", 171);
	// n___ = printf("-->%-7.4x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.4x<--\n", 171);
	// n___ = printf("-->%-#7.4x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.1x<--\n", 171);
	// n___ = printf("-->%-#7.1x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#3.5x<--\n", 171);
	// n___ = printf("-->%-#3.5x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-.5x<--\n", 171);
	// n___ = printf("-->%-.5x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#1.1x<--\n", 171);
	// n___ = printf("-->%-#1.1x<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0.x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%0.x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0.1x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%0.1x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%07.1x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%07.1x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%07.4x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%07.4x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#7.4x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%0#7.4x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-#7.4x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#7.1x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-#7.1x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#3.5x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-#3.5x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-.5x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-.5x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#1.1x<--\n", 171); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%0-#1.1x<--\n", 171); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#01.5x<--\n", 171); // <-- x (error: 0 with .)
	// n___ = printf("-->%#01.5x<--\n", 171); // <-- x (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-3x<--\n", 171); // <-- x (error: 0 with -)
	// n___ = printf("-->%0-3x<--\n", 171); // <-- x (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#1x<--\n", 171); // <-- x (error: 0 with -)
	// n___ = printf("-->%0-#1x<--\n", 171); // <-- x (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#3x<--\n", 171); // <-- x (error: 0 with -)
	// n___ = printf("-->%0-#3x<--\n", 171); // <-- x (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#5x<--\n", 171); // <-- x (error: 0 with -)
	// n___ = printf("-->%0-#5x<--\n", 171); // <-- x (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%05x<--\n", 171); // <-- x
	// n___ = printf("-->%05x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#5x<--\n", 171); // <-- x
	// n___ = printf("-->%0#5x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.1x<--\n", 171); // <-- x
	// n___ = printf("-->%.1x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.5x<--\n", 171); // <-- x
	// n___ = printf("-->%.5x<--\n", 171); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%x<--\n", 0); // <-- x
	// n___ = printf("-->%x<--\n", 0); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#x<--\n", 0); // <-- x
	// n___ = printf("-->%#x<--\n", 0); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#3x<--\n", 0); // <-- x
	// n___ = printf("-->%#3x<--\n", 0); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.6x<--\n", 0); // <-- x
	// n___ = printf("-->%#7.6x<--\n", 0); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.6x<--\n", 0); // <-- x
	// n___ = printf("-->%-#7.6x<--\n", 0); // <-- x
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-0#7.6x<--\n", 0); // <-- x (error: 0 with - and .)
	// n___ = printf("-->%-0#7.6x<--\n", 0); // <-- x (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- x --|\n");

	// printf("|-- get -->\n");
	// printf("-->%s<--\n", ft_get_types());
	// printf("-->%s<--\n", ft_get_flags());
	// printf("-->%s<--\n", ft_get_null('s'));
	// printf("-->%s<--\n", ft_get_null('p'));
	// printf("-->%s<--\n", ft_get_null('?'));
	// printf("-->%s<--\n", ft_get_prefix(0, 0, 'x'));
	// printf("-->%s<--\n", ft_get_prefix(0, 0, 'X'));
	// printf("-->%s<--\n", ft_get_prefix(0, 0, 's'));
	// printf("-->%s<--\n", ft_get_prefix(1, 1, 'x'));
	// printf("-->%s<--\n", ft_get_prefix(1, 1, 'X'));
	// printf("-->%s<--\n", ft_get_prefix(1, 1, 's'));
	// printf("<-- get --|\n");
	test_check(n * 0, n___ * 0);
	printf("<-- TEST --|\n");
	return (1);
}
