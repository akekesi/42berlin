/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	i++;
	dup = (char *)malloc(sizeof(char) * i);
	if (!dup)
		return (NULL);
	while (i)
	{
		i--;
		dup[i] = str[i];
	}
	return (dup);
}

int	main(void)
{
	char	str[4] = "abc\0";
	char	*dup;

	dup = ft_strdup(str);
	printf("-->%s<--\n", str);
	printf("-->%s<--\n", dup);
}
