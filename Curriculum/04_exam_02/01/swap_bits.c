/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

#include <unistd.h>
#include <stdio.h>

char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void	ft_dec_to_bin_placeholder(int n, int p)
{
	int	i;
	int	pw;

	while (p)
	{
		i = 0;
		pw = 1;
		while (i < p - 1)
		{
			pw *= 2;
			i++;
		}
		if (n < pw)
			write(1, "0", 1);
		p--;
	}
}

void	ft_dec_to_bin_recursive(int n)
{
	char	c;

	if (n < 2)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_dec_to_bin_recursive(n / 2);
		c = n % 2 + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	int				p;
	unsigned char	octet;
	unsigned char	octet_swapped;

	p = 8;
	octet = 11;
	octet_swapped = swap_bits(octet);
	ft_dec_to_bin_placeholder(octet, p);
	ft_dec_to_bin_recursive(octet);
	printf("\n");
	ft_dec_to_bin_placeholder(octet_swapped, p);
	ft_dec_to_bin_recursive(octet_swapped);
	printf("\n");
	printf("%d --> %d\n", octet, octet_swapped);
}
