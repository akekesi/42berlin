/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
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
			new = 0;
			if (n == n_)
				return (i);
			n_++;
		}
		if (ft_isspace(str[i]))
			new = 1;
		i++;
	}
	return (n_);
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

void	ft_rev_wstr(char *str)
{
	int	n;
	int	p;

	n = ft_words_n_p(str, -1);
	while (n)
	{
		n--;
		p = ft_words_n_p(str, n);
		ft_putstr_space(str + p);
		if (n)
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev_wstr(argv[1]);
	write(1, "\n", 1);
}
