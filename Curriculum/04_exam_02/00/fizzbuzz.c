/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5,
it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
*/

#include <unistd.h>

void	ft_write_int(int n)
{
	char	c;

	if (n > 9)
	{
		ft_write_int(n / 10);
		n = n % 10;
	}
	c = n + '0';
	write(1, &c, 1);
}

void	ft_fizzbuzz(void)
{
	int	i;

	i = 1;
	while (i < 101)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (i % 3 != 0 && i % 5 != 0)
			ft_write_int(i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	ft_fizzbuzz();
}
