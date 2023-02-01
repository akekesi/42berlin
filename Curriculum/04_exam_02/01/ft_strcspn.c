/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *str, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	main(void)
{
	const char	str1[4] = "abc\0";
	const char	str2[4] = "abc\0";

	printf("%ld\n", strcspn(str1, str2));
	printf("%ld\n", ft_strcspn(str1, str2));
}
