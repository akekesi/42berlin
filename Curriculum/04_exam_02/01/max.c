/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	tmp;

	if (!len)
		return (0);
	tmp = tab[--len];
	while (len)
	{
		len--;
		if (tab[len] > tmp)
			tmp = tab[len];
	}
	return (tmp);
}

int	main(void)
{
	int	numbers1[9] = {-100, -11, -1, 0, 1, 11, 13, 42, 999};
	int	numbers2[9] = {100, 11, 111, 1010, 1, 1010, 13, 42, -999};
	int	numbers3[0] = {};
	int	numbers4[1] = {13};
	int	numbers5[2] = {1, 0};

	printf("%d\n", max(numbers1, 9));
	printf("%d\n", max(numbers2, 9));
	printf("%d\n", max(numbers3, 0));
	printf("%d\n", max(numbers4, 1));
	printf("%d\n", max(numbers5, 2));
}
