/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>
#include <stdlib.h>

void	ft_print_bits_0_recursive(int n, int p)
{
	int	i;
	int	n_;

	while (p)
	{
		p--;
		i = 0;
		n_ = 2;
		while (i < p)
		{
			n_ *= 2;
			i++;
		}
		if (n_ > n)
			write(1, "0", 1);
	}
}

void	ft_print_bits_recursive(int n)
{
	char	c;

	if (n > 1)
		ft_print_bits_recursive(n / 2);
	c = n % 2 + '0';
	write(1, &c, 1);
}

void	print_bits_recursive(unsigned char octet)
{
	int	i;

	i = 8;
	ft_print_bits_0_recursive(octet, i - 1);
	ft_print_bits_recursive(octet);
}

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 256;
	while (i)
	{
		i--;
		print_bits(i);
		write(1, "\n", 1);
		print_bits_recursive(i);
		write(1, "\n", 1);
	}
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			print_bits(atoi(argv[i]));
			write(1, "\n", 1);
			print_bits_recursive(atoi(argv[i]));
			write(1, "\n", 1);
			i++;
		}
	}
}
