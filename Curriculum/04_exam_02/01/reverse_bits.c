/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 8;
	while (i--)
	{
		c = (octet >> i & 1) + '0';
		write(1, &c, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	octet_reverse;

	octet_reverse = 0;
	i = 0;
	while (i < 8)
	{
		if ((octet & (1 << i)))
			octet_reverse |= 1 << (8 - 1 - i);
		i++;
	}
	return (octet_reverse);
}

int	main(int argc, char **argv)
{
	int	i;
	int	i_;

	i = 256;
	while (i--)
	{
		write(1, "\n", 1);
		print_bits(i);
		write(1, "\n", 1);
		i_ = reverse_bits(i);
		print_bits(i_);
		write(1, "\n", 1);
	}
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			write(1, "\n", 1);
			print_bits(atoi(argv[i]));
			write(1, "\n", 1);
			i_ = reverse_bits(atoi(argv[i]));
			print_bits(i_);
			write(1, "\n", 1);
			i++;
		}
	}
}
