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

	// int	n;
	// int	n___;
	
	// n = 0;
	// n___ = 0;

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

	// printf("|-- X -->\n");
	// n = ft_printf("-->%X<--\n", 171); // <-- X
	// n___ = printf("-->%X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#X<--\n", 171); // <-- X
	// n___ = printf("-->%#X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->% X<--\n", 171); // <-- X (error: space used)
	// n___ = printf("-->% X<--\n", 171); // <-- X (error: space used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%+X<--\n", 171); // <-- X (error: + used)
	// n___ = printf("-->%+X<--\n", 171); // <-- X (error: + used)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%3X<--\n", 171); // <-- X
	// n___ = printf("-->%3X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#1X<--\n", 171); // <-- X
	// n___ = printf("-->%#1X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#3X<--\n", 171); // <-- X
	// n___ = printf("-->%#3X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#5X<--\n", 171); // <-- X
	// n___ = printf("-->%#5X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-3X<--\n", 171); // <-- X
	// n___ = printf("-->%-3X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#1X<--\n", 171); // <-- X
	// n___ = printf("-->%-#1X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#3X<--\n", 171); // <-- X
	// n___ = printf("-->%-#3X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#5X<--\n", 171); // <-- X
	// n___ = printf("-->%-#5X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%03X<--\n", 171); // <-- X
	// n___ = printf("-->%03X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#1X<--\n", 171); // <-- X
	// n___ = printf("-->%0#1X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#3X<--\n", 171); // <-- X
	// n___ = printf("-->%0#3X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#5X<--\n", 171); // <-- X
	// n___ = printf("-->%0#5X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#7X<--\n", 171); // <-- X
	// n___ = printf("-->%0#7X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7X<--\n", 171); // <-- X
	// n___ = printf("-->%-#7X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#05X<--\n", 171); // <-- X (error: 0 with -)
	// n___ = printf("-->%-#05X<--\n", 171); // <-- X (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#09.X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%#09.X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#09.X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%-#09.X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#09.3X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%#09.3X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#09.3X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%-#09.3X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.X<--\n", 171);
	// n___ = printf("-->%.X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.1X<--\n", 171);
	// n___ = printf("-->%.1X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.1X<--\n", 171);
	// n___ = printf("-->%7.1X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%7.4X<--\n", 171);
	// n___ = printf("-->%7.4X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.4X<--\n", 171);
	// n___ = printf("-->%#7.4X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-7.4X<--\n", 171);
	// n___ = printf("-->%-7.4X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.4X<--\n", 171);
	// n___ = printf("-->%-#7.4X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.1X<--\n", 171);
	// n___ = printf("-->%-#7.1X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#3.5X<--\n", 171);
	// n___ = printf("-->%-#3.5X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-.5X<--\n", 171);
	// n___ = printf("-->%-.5X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#1.1X<--\n", 171);
	// n___ = printf("-->%-#1.1X<--\n", 171);
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0.X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%0.X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0.1X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%0.1X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%07.1X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%07.1X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%07.4X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%07.4X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#7.4X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%0#7.4X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-#7.4X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#7.1X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-#7.1X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#3.5X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-#3.5X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-.5X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-.5X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#1.1X<--\n", 171); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%0-#1.1X<--\n", 171); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#01.5X<--\n", 171); // <-- X (error: 0 with .)
	// n___ = printf("-->%#01.5X<--\n", 171); // <-- X (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-3X<--\n", 171); // <-- X (error: 0 with -)
	// n___ = printf("-->%0-3X<--\n", 171); // <-- X (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#1X<--\n", 171); // <-- X (error: 0 with -)
	// n___ = printf("-->%0-#1X<--\n", 171); // <-- X (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#3X<--\n", 171); // <-- X (error: 0 with -)
	// n___ = printf("-->%0-#3X<--\n", 171); // <-- X (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0-#5X<--\n", 171); // <-- X (error: 0 with -)
	// n___ = printf("-->%0-#5X<--\n", 171); // <-- X (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%05X<--\n", 171); // <-- X
	// n___ = printf("-->%05X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%0#5X<--\n", 171); // <-- X
	// n___ = printf("-->%0#5X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.1X<--\n", 171); // <-- X
	// n___ = printf("-->%.1X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%.5X<--\n", 171); // <-- X
	// n___ = printf("-->%.5X<--\n", 171); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%X<--\n", 0); // <-- X
	// n___ = printf("-->%X<--\n", 0); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#X<--\n", 0); // <-- X
	// n___ = printf("-->%#X<--\n", 0); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#3X<--\n", 0); // <-- X
	// n___ = printf("-->%#3X<--\n", 0); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%#7.6X<--\n", 0); // <-- X
	// n___ = printf("-->%#7.6X<--\n", 0); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-#7.6X<--\n", 0); // <-- X
	// n___ = printf("-->%-#7.6X<--\n", 0); // <-- X
	// if (!test_check(n, n___))
	// 	return (0);
	// n = ft_printf("-->%-0#7.6X<--\n", 0); // <-- X (error: 0 with - and .)
	// n___ = printf("-->%-0#7.6X<--\n", 0); // <-- X (error: 0 with - and .)
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- X --|\n");

	// printf("|-- p -->\n");
	// n = ft_printf("-->%7p<--\n", 171); // <-- p
	// n___ = printf("-->%7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->% 7p<--\n", 171); // <-- p
	// n___ = printf("-->% 7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+7p<--\n", 171); // <-- p
	// n___ = printf("-->%+7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-7p<--\n", 171); // <-- p
	// n___ = printf("-->%-7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 7p<--\n", 171); // <-- p
	// n___ = printf("-->%- 7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+7p<--\n", 171); // <-- p
	// n___ = printf("-->%-+7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%07p<--\n", 171); // <-- p
	// n___ = printf("-->%07p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0 7p<--\n", 171); // <-- p
	// n___ = printf("-->%0 7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0+7p<--\n", 171); // <-- p
	// n___ = printf("-->%0+7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0-7p<--\n", 171); // <-- p
	// n___ = printf("-->%0-7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0- 7p<--\n", 171); // <-- p
	// n___ = printf("-->%0- 7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0-+7p<--\n", 171); // <-- p
	// n___ = printf("-->%0-+7p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%07.6p<--\n", 171); // <-- p
	// n___ = printf("-->%07.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0 7.6p<--\n", 171); // <-- p
	// n___ = printf("-->%0 7.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0+7.6p<--\n", 171); // <-- p
	// n___ = printf("-->%0+7.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0-7.6p<--\n", 171); // <-- p
	// n___ = printf("-->%0-7.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0- 7.6p<--\n", 171); // <-- p
	// n___ = printf("-->%0- 7.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0-+7.6p<--\n", 171); // <-- p
	// n___ = printf("-->%0-+7.6p<--\n", 171); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0-+8.7p<--\n", 0); // <-- p
	// n___ = printf("-->%0-+8.7p<--\n", 0); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%0+8.7p<--\n", 0); // <-- p
	// n___ = printf("-->%0+8.7p<--\n", 0); // <-- p
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- p --|\n");

	// printf("|-- d/i -->\n");
	// n = ft_printf("-->%d<--\n", 123); // <-- d/i
	// n___ = printf("-->%d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->% d<--\n", 123); // <-- d/i
	// n___ = printf("-->% d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+d<--\n", 123); // <-- d/i
	// n___ = printf("-->%+d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+ d<--\n", 123); // <-- d/i (error: space with +)
	// n___ = printf("-->%+ d<--\n", 123); // <-- d/i (error: space with +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%#+ d<--\n", 123); // <-- d/i (error: #)
	// n___ = printf("-->%#+ d<--\n", 123); // <-- d/i (error: #)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05d<--\n", 123); // <-- d/i
	// n___ = printf("-->%05d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-05d<--\n", 123); // <-- d/i (error: 0 with -)
	// n___ = printf("-->%-05d<--\n", 123); // <-- d/i (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%-.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%7.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%7.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-7.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%-7.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+7.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%-+7.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 7.5d<--\n", 123); // <-- d/i
	// n___ = printf("-->%- 7.5d<--\n", 123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+07.5d<--\n", 123); // <-- d/i (error: 0 with . and -)
	// n___ = printf("-->%-+07.5d<--\n", 123); // <-- d/i (error: 0 with . and -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 07.5d<--\n", 123); // <-- d/i (error: 0 with . and -)
	// n___ = printf("-->%- 07.5d<--\n", 123); // <-- d/i (error: 0 with . and -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- +08.6d<--\n", 123); // <-- d/i (error: 0 with ., - and +)
	// n___ = printf("-->%- +08.6d<--\n", 123); // <-- d/i (error: 0 with ., - and +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05.d<--\n", 123); // <-- d/i (error: 0 with .)
	// n___ = printf("-->%05.d<--\n", 123); // <-- d/i (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%d<--\n", -123); // <-- d/i
	// n___ = printf("-->%d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->% d<--\n", -123); // <-- d/i
	// n___ = printf("-->% d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+d<--\n", -123); // <-- d/i
	// n___ = printf("-->%+d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+ d<--\n", -123); // <-- d/i (error: space with +)
	// n___ = printf("-->%+ d<--\n", -123); // <-- d/i (error: space with +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%#+ d<--\n", -123); // <-- d/i (error: #)
	// n___ = printf("-->%#+ d<--\n", -123); // <-- d/i (error: #)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05d<--\n", -123); // <-- d/i
	// n___ = printf("-->%05d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-05d<--\n", -123); // <-- d/i (error: 0 with -)
	// n___ = printf("-->%-05d<--\n", -123); // <-- d/i (error: 0 with -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%-.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%7.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%7.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-7.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%-7.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+7.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%-+7.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 7.5d<--\n", -123); // <-- d/i
	// n___ = printf("-->%- 7.5d<--\n", -123); // <-- d/i
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+07.5d<--\n", -123); // <-- d/i (error: 0 with . and -)
	// n___ = printf("-->%-+07.5d<--\n", -123); // <-- d/i (error: 0 with . and -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 07.5d<--\n", -123); // <-- d/i (error: 0 with . and -)
	// n___ = printf("-->%- 07.5d<--\n", -123); // <-- d/i (error: 0 with . and -)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- +08.6d<--\n", -123); // <-- d/i (error: 0 with ., - and +)
	// n___ = printf("-->%- +08.6d<--\n", -123); // <-- d/i (error: 0 with ., - and +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05.d<--\n", -123); // <-- d/i (error: 0 with .)
	// n___ = printf("-->%05.d<--\n", -123); // <-- d/i (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- +08.6d<--\n", 0); // <-- d/i (error: 0 with ., - and +)
	// n___ = printf("-->%- +08.6d<--\n", 0); // <-- d/i (error: 0 with ., - and +)
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- d/i --|\n");

	// printf("|-- u -->\n");
	// n = ft_printf("-->%u<--\n", 123); // <-- u
	// n___ = printf("-->%u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->% u<--\n", 123); // <-- u (error: space)
	// n___ = printf("-->% u<--\n", 123); // <-- u (error: space)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+u<--\n", 123); // <-- u (error: +)
	// n___ = printf("-->%+u<--\n", 123); // <-- u (error: +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+ u<--\n", 123); // <-- u (error: space and  +)
	// n___ = printf("-->%+ u<--\n", 123); // <-- u (error: space and +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%#+ u<--\n", 123); // <-- u (error: #, space and  +)
	// n___ = printf("-->%#+ u<--\n", 123); // <-- u (error: #, space and  +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05u<--\n", 123); // <-- u
	// n___ = printf("-->%05u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%.5u<--\n", 123); // <-- u
	// n___ = printf("-->%.5u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-05u<--\n", 123); // <-- u (error: 0)
	// n___ = printf("-->%-05u<--\n", 123); // <-- u (error: 0)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-.5u<--\n", 123); // <-- u
	// n___ = printf("-->%-.5u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%7.5u<--\n", 123); // <-- u
	// n___ = printf("-->%7.5u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-7.5u<--\n", 123); // <-- u
	// n___ = printf("-->%-7.5u<--\n", 123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+7.5u<--\n", 123); // <-- u (error: +)
	// n___ = printf("-->%-+7.5u<--\n", 123); // <-- u (error: +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 7.5u<--\n", 123); // <-- u (error: space)
	// n___ = printf("-->%- 7.5u<--\n", 123); // <-- u (error: space)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+07.5u<--\n", 123); // <-- u (error: +, 0, - and .)
	// n___ = printf("-->%-+07.5u<--\n", 123); // <-- u (error: +, 0, - and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 07.5u<--\n", 123); // <-- u (error: space, 0, - and .)
	// n___ = printf("-->%- 07.5u<--\n", 123); // <-- u (error: space, 0, - and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- +08.6u<--\n", 123); // <-- u (error: space, 0, -, + and .)
	// n___ = printf("-->%- +08.6u<--\n", 123); // <-- u (error: space, 0, -, + and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05.u<--\n", 123); // <-- u (error: 0 with .)
	// n___ = printf("-->%05.u<--\n", 123); // <-- u (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%u<--\n", -123); // <-- u
	// n___ = printf("-->%u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->% u<--\n", -123); // <-- u (error: space)
	// n___ = printf("-->% u<--\n", -123); // <-- u (error: space)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+u<--\n", -123); // <-- u (error: +)
	// n___ = printf("-->%+u<--\n", -123); // <-- u (error: +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%+ u<--\n", -123); // <-- u (error: space and  +)
	// n___ = printf("-->%+ u<--\n", -123); // <-- u (error: space and +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%#+ u<--\n", -123); // <-- u (error: #, space and  +)
	// n___ = printf("-->%#+ u<--\n", -123); // <-- u (error: #, space and  +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05u<--\n", -123); // <-- u
	// n___ = printf("-->%05u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%.5u<--\n", -123); // <-- u
	// n___ = printf("-->%.5u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-05u<--\n", -123); // <-- u (error: 0)
	// n___ = printf("-->%-05u<--\n", -123); // <-- u (error: 0)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-.5u<--\n", -123); // <-- u
	// n___ = printf("-->%-.5u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%7.5u<--\n", -123); // <-- u
	// n___ = printf("-->%7.5u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-7.5u<--\n", -123); // <-- u
	// n___ = printf("-->%-7.5u<--\n", -123); // <-- u
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+7.5u<--\n", -123); // <-- u (error: +)
	// n___ = printf("-->%-+7.5u<--\n", -123); // <-- u (error: +)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 7.5u<--\n", -123); // <-- u (error: space)
	// n___ = printf("-->%- 7.5u<--\n", -123); // <-- u (error: space)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%-+07.5u<--\n", -123); // <-- u (error: +, 0, - and .)
	// n___ = printf("-->%-+07.5u<--\n", -123); // <-- u (error: +, 0, - and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- 07.5u<--\n", -123); // <-- u (error: space, 0, - and .)
	// n___ = printf("-->%- 07.5u<--\n", -123); // <-- u (error: space, 0, - and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%- +08.6u<--\n", -123); // <-- u (error: space, 0, -, + and .)
	// n___ = printf("-->%- +08.6u<--\n", -123); // <-- u (error: space, 0, -, + and .)
	// if (!test_check(n, n___))
	// 	return (0);

	// n = ft_printf("-->%05.u<--\n", -123); // <-- u (error: 0 with .)
	// n___ = printf("-->%05.u<--\n", -123); // <-- u (error: 0 with .)
	// if (!test_check(n, n___))
	// 	return (0);
	// printf("<-- u --|\n");

	// printf("|-- get -->\n");
	// printf("-->%s<--\n", ft_get_types());
	// printf("-->%s<--\n", ft_get_flags());
	// printf("-->%s<--\n", ft_get_null('s'));
	// printf("-->%s<--\n", ft_get_null('p'));
	// printf("-->%s<--\n", ft_get_null('?'));
	// printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'x', 0));
	// printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'X', 0));
	// printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', '+'));
	// printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', ' '));
	// printf("-->%s<--\n", ft_get_prefix_main(0, 1, 'p', 0));
	// printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'x', 0));
	// printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'X', 0));
	// printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', '+'));
	// printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', ' '));
	// printf("-->%s<--\n", ft_get_prefix_main(1, 1, 'p', 0));
	// printf("<-- get --|\n");

	printf("<-- TEST --|\n");
	return (1);
}
