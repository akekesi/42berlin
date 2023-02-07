/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putstr_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_words_n_p(char *str, int n)
{
	int	i;
	int	n_;
	int	new;

	i = 0;
	n_ = 0;
	new = 1;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && new)
		{
			if (n == n_)
				return (i);
			n_++;
			new = 0;
		}
		if (ft_isspace(str[i]))
			new = 1;
		i++;
	}
	return (n_);
}

void	ft_rostring(char *str)
{
	int	i;
	int	n;
	int	p;

	i = 1;
	n = ft_words_n_p(str, -1);
	while (i < n)
	{
		p = ft_words_n_p(str, i);
		ft_putstr_space(str + p);
		write(1, " ", 1);
		i++;
	}
	p = ft_words_n_p(str, 0);
	ft_putstr_space(str + p);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rostring(argv[1]);
	write(1, "\n", 1);
}
