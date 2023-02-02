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

void ft_dec_to_hex(int n, int p)
{
	char	c;

	while (p)
	{
		if ()
		write(1, "0", 1);
	}
	while (n)
	{
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 8;
	octet_swapped = swap_bits(octet);
	printf("%d --> %d\n", octet, octet_swapped);
	swap_bits(octet);
}
