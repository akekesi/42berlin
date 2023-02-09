/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		n;
	char	c;

	if (!str)
		return (NULL);
	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		c = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = c;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ft_strrev(argv[1]));
	}
}
