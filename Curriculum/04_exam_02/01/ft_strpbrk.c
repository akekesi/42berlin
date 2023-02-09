/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *str1, const char *str2)
{
	int	i;
	int	j;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
				return (&((char *)str1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_strpbrk("abc", "xax"));
	printf("%s\n",    strpbrk("abc", "xax"));
	printf("%s\n", ft_strpbrk("abc", "xbx"));
	printf("%s\n",    strpbrk("abc", "xbx"));
	printf("%s\n", ft_strpbrk("abc", "xcx"));
	printf("%s\n",    strpbrk("abc", "xcx"));
	printf("%s\n", ft_strpbrk("abc", "xxx"));
	printf("%s\n",    strpbrk("abc", "xxx"));
	printf("%s\n", ft_strpbrk("", "xxx"));
	printf("%s\n",    strpbrk("", "xxx"));
	printf("%s\n", ft_strpbrk("abc", ""));
	printf("%s\n",    strpbrk("abc", ""));
	printf("%s\n", ft_strpbrk("", ""));
	printf("%s\n",    strpbrk("", ""));
	printf("%s\n", ft_strpbrk(NULL, NULL));
	printf("%s\n",    strpbrk(NULL, NULL));
}
