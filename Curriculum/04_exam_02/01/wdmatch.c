/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int	ft_strchr_p(char *str, char c, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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

int	ft_wdmatch(char *str1, char *str2)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (str1[i])
	{
		p = ft_strchr_p(str2, str1[i], p);
		if (p == -1)
			return (0);
		i++;
		p++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_wdmatch(argv[1], argv[2]))
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
}
