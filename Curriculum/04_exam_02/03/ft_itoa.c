/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_intabs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}	
	while (i < len)
	{
		len--;
		str[len] = ft_intabs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	main(void)
{
	int	i;
	int	n[] = {
		-2147483648,
		-111,
		-2,
		-1,
		0,
		1,
		2,
		3,
		10,
		111,
		2147483647,
	};

	i = 11;
	while (i)
	{
		i--;
		printf("%d\n", n[i]);
		printf("%s\n", ft_itoa(n[i]));
		printf("---\n");
	}
}
