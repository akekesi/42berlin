/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>
#include <string.h>

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *str1, const char *str2)
{
	size_t	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i])
	{
		if (ft_strchr((char *)str2, str1[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%ld\n", ft_strspn(argv[1], argv[2]));
		printf("%ld\n",    strspn(argv[1], argv[2]));
	}
}
