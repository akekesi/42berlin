/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int	ft_isprime(int n)
{
	int	d;

	if (n < 2)
		return (0);
	d = 2;
	while (d < n / 2)
	{
		if (!(n % d))
			return (0);
		d++;
	}
	return (1);
}

void	ft_fprime(int n)
{
	int	p;
	int	s;

	if (n == 1)
		printf("1");
	p = 2;
	s = 0;
	while (p <= n)
	{
		if (!(n % p))
		{
			if (s)
				printf("*");
			printf("%d", p);
			s = 1;
			n /= p;
		}
		else
			p++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_fprime(atoi(argv[1]));
	printf("\n");
}
