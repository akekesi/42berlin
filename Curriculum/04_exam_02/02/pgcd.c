/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int	ft_hcf(int a, int b)
{
	int	tmp;

	if (!a || !b)
		return (0);
	if (a > b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}
	tmp = a;
	while (1)
	{
		if (!(b % tmp) && !(a % tmp))
			return (tmp);
		tmp--;
	}
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	n;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		n = ft_hcf(a, b);
		printf("%d", n);
	}
	printf("\n");
}
