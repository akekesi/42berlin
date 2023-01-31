/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	dest[7] = "xxxxxx\0";
	char	src[5] = "abcd\0";

	printf("dest: -->%s<--\n", dest);
	printf("src:  -->%s<--\n", src);
	ft_strcpy(dest, src);
	printf("dest: -->%s<--\n", dest);
	printf("src:  -->%s<--\n", src);
}
