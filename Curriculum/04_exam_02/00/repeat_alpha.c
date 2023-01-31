/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_str_call(char *str, void (*f)(char c));
void	ft_repeat_char(char c);
int		ft_isalpha(char c);

void	ft_str_call(char *str, void (*f)(char c))
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			f(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_repeat_char(char c)
{
	int	i;

	if ('a' <= c && c <= 'z')
		i = 1 + c - 'a';
	if ('A' <= c && c <= 'Z')
		i = 1 + c - 'A';
	while (i)
	{
		write(1, &c, 1);
		i--;
	}
}

int	ft_isalpha(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_str_call(argv[1], ft_repeat_char);
	}
	write (1, "\n", 1);
}
