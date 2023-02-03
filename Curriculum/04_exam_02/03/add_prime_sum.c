/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int	ft_atoi_pos(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int	ft_isprime(int n)
{
	int	d;

	d = 2;
	if (n < 2)
		return (0);
	while (d < n)
	{
		if (!(n % d))
			return (0);
		d++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_add_prime_sum(char *str)
{
	int	n;
	int	s;

	n = ft_atoi_pos(str);
	s = n;
	while (n > 1)
	{
		n--;
		if (ft_isprime(n))
			s += n;
	}
	ft_putnbr(s);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1][0] != '-')
			ft_add_prime_sum(argv[1]);
		else
			write(1, "0", 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
