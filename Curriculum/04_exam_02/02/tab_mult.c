/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

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

void	ft_tab_mult(char *str)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putstr(str);
		write(1, " = ", 3);
		ft_putnbr(i * ft_atoi(str));
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_tab_mult(argv[1]);
	else
		write(1, "\n", 1);
}
