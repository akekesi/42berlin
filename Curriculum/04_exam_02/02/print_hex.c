/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_atoi(char *str)
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

void	ft_dec_to_hex(int n)
{
	if (n > 15)
		ft_dec_to_hex(n / 16);
	n = n % 16;
	if (n > 9)
		n = n - 10 + 'a';
	if (n < 10)
		n = n + '0';
	write(1, &n, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_dec_to_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
