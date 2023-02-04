/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/

#include <unistd.h>

int	ft_strchar(char *str, char c, int start)
{
	while (str[start])
	{
		if (str[start] == c)
			return (start);
		start++;
	}
	return (-1);
}

int	ft_hidenp(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		j = ft_strchar(str2, str1[i], j);
		if (j == -1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		n;
	char	c;

	if (argc == 3)
	{
		n = ft_hidenp(argv[1], argv[2]);
		c = n + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}
