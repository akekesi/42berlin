/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 22:54:34 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	main(void)
{
	printf("*** main test started ***\n");
	printf("|-- test printf -->\n");
	// // ft_printf("c%cs%sp%pd%di%iu%ux%xX%X%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// // ft_printf("%cc%ss%pp%dd%ii%uu%xx%XX%%%", 1, 2, 3, 4, 5, 6, 7, 8, 9);

	int		n;
	int		n___;
	char	prefix[] = "-->";
	char	suffix[] = "<--";

	n = 0;
	n___ = 0;
	ft_printf("%s", prefix);
	n = ft_printf("% s", ""); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("% s", ""); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	// ft_printf("%s", prefix);
	// n = ft_printf(" % 1s", ""); // <-- ' 's just with 0
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf(" % 1s", ""); // <-- ' 's just with 0
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);
	
	// ft_printf("%s", prefix);
	// n = ft_printf("% 1s ", ""); // <-- ' 's just with 0
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("% 1s ", ""); // <-- ' 's just with 0
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);
	
	ft_printf("%s", prefix);
	
	n = ft_printf(" % s ", ""); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s ", ""); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	ft_printf("%s", prefix);
	n = ft_printf(" % s ", "-"); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s ", "-"); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	ft_printf("%s", prefix);
	n = ft_printf(" % s % s ", "", "-"); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s % s ", "", "-"); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	ft_printf("%s", prefix);
	n = ft_printf(" % s % s ", " - ", ""); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s % s ", " - ", ""); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	ft_printf("%s", prefix);
	n = ft_printf(" % s % s % s % s ", " - ", "", "4", ""); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s % s % s % s ", " - ", "", "4", ""); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	ft_printf("%s", prefix);
	n = ft_printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "); // <-- ' 's
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "); // <-- ' 's
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
	
	// ft_printf("%s", prefix);
	// n = ft_printf("%     d", 0); // <-- ' 'd
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("%     d", 0); // <-- ' 'd
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("%   +  d", 0); // <-- ' 'd
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("%   +  d", 0); // <-- ' 'd
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("% d", 10); // <-- ' 'd
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("% d", 10); // <-- ' 'd
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("% d", -1); // <-- ' 'd
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("% d", -1); // <-- ' 'd
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("%# # +-#d", 0); // <-- +d
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("%# # +-#d", 0); // <-- +d
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("%# # +-#x", 0); // <-- #x
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("%# # +-#x", 0); // <-- #x
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

	// ft_printf("%s", prefix);
	// n = ft_printf("%# # +-#x", 10); // <-- #x
	// ft_printf("%s\n", suffix);
	// printf("%s", prefix);
	// n___ = printf("%# # +-#x", 10); // <-- #x
	// printf("%s\n", suffix);
	// if (!test_check(n, n___))
	// 	return (0);

/*
	ft_printf("%s", prefix);
	n = ft_printf("%c", 0); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", 0); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c", '\0'); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", '\0'); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c", NULL); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", NULL); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c", '\n'); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", '\n'); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c", 'k'); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", 'k'); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c", 'e'); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c", 'e'); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%c%c%c%c :)", 'k', 'e', 'k', 'i'); // <-- c
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%c%c%c%c :)", 'k', 'e', 'k', 'i'); // <-- c
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s", 0); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s", 0); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s", ""); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s", ""); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s", NULL); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s", NULL); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s", "\0"); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s", "\0"); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf(" NULL %s NULL ", NULL); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf(" NULL %s NULL ", NULL); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s", "keki :)"); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s", "keki :)"); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%s%s", "keki ", ":)"); // <-- s
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%s%s", "keki ", ":)"); // <-- s
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p", 0); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p", 0); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p", NULL); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p", NULL); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p", 1); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p", 1); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p %p", 10, 19); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p %p", 10, 19); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p", 1984); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p", 1984); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%p", 170); // <-- p
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%p", 170); // <-- p
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", 0); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", 0); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", NULL); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", NULL); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", 2147483647); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", 2147483647); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", 2147483647); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", 2147483647); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", -2147483648); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", -2147483648); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", 2147483647 + 1); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", 2147483647 + 1); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", 1234567); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", 1234567); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);

	ft_printf("%s", prefix);
	n = ft_printf("%d", -101); // <-- d
	ft_printf("%s\n", suffix);
	printf("%s", prefix);
	n___ = printf("%d", -101); // <-- d
	printf("%s\n", suffix);
	if (!test_check(n, n___))
		return (0);
*/



	// // n = ft_printf("-->keki<--\n-->%c%c%c%c<--\n", 'k', 'e', 'k', 'i');
	// n___ = printf("-->keki<--\n-->%c%c%c%c<--\n", 'k', 'e', 'k', 'i');

	// n = printf("-->0<--\n-->%x<--\n", 0);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->0<--\n-->%x<--\n", 0);
	// ft_printf("n: %i\n", n);
	// n = printf("-->a<--\n-->%x<--\n", 10);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->a<--\n-->%x<--\n", 10);
	// ft_printf("n: %i\n", n);
	// n = printf("-->13<--\n-->%x<--\n", 19);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->13<--\n-->%x<--\n", 19);
	// ft_printf("n: %i\n", n);
	// n = printf("-->7c0<--\n-->%x<--\n", 1984);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->7c0<--\n-->%x<--\n", 1984);
	// ft_printf("n: %i\n", n);

	// n = ft_printf("-->0<--\n-->%X<--\n", 0);
	// ft_printf("n: %i\n", n);
	// n = printf("-->0<--\n-->%X<--\n", 0);
	// ft_printf("n: %i\n", n);
	// n = printf("-->A<--\n-->%X<--\n", 10);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->A<--\n-->%X<--\n", 10);
	// ft_printf("n: %i\n", n);
	// n = printf("-->13<--\n-->%X<--\n", 19);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->13<--\n-->%X<--\n", 19);
	// ft_printf("n: %i\n", n);
	// n = printf("-->7C0<--\n-->%X<--\n", 1984);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->7C0<--\n-->%X<--\n", 1984);
	// ft_printf("n: %i\n", n);

	// n = ft_printf("-->0<--\n-->%p<--\n", 0);
	// ft_printf("n: %i\n", n);
	// n = printf("-->0x1<--\n-->%p<--\n", 1);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->0x1<--\n-->%p<--\n", 1);
	// ft_printf("n: %i\n", n);
	// n = printf("-->0x7C0<--\n-->%p<--\n", 1984);
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->0x7C0<--\n-->%p<--\n", 1984);
	// ft_printf("n: %i\n", n);

	// n = printf("-->without args<--\n");
	// ft_printf("n: %i\n", n);
	// n = ft_printf("-->without args<--\n");
	// ft_printf("n: %i\n", n);

	// n = printf("");
	// ft_printf("n: %i\n", n);
	// n = ft_printf("");
	// ft_printf("n: %i\n", n);
	// n = printf(" ");
	// printf("n: %i\n", n);
	// n = ft_printf(" ");
	// ft_printf("n: %i\n", n);
	// n = printf(0);
	// ft_printf("n: %i\n", n);
	// n = ft_printf(0);
	// ft_printf("n: %i\n", n);
	// n = printf(NULL);
	// ft_printf("n: %i\n", n);
	// n = ft_printf(NULL);
	// ft_printf("n: %i\n", n);
	// n = printf("\0");
	// ft_printf("n: %i\n", n);
	// n = ft_printf("\0");
	// ft_printf("n: %i\n", n);

	// n = printf("%c%s%p%d%i%u%x%X%%");
	// ft_printf("n: %i\n", n);
	// n = ft_printf("%c%s%p%d%i%u%x%X%%");
	// ft_printf("n: %i\n", n);
	// ft_printf("n: %i\n", n);

	printf("<-- test printf --|\n");
	printf("*** main test finished ***\n");
	return (0);
}
