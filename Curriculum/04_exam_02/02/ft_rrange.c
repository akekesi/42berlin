/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*rrange;

	rrange = (int *)malloc(sizeof(int) * (end - start + 1));
	if (!rrange)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		rrange[i] = end - i;
		i++;
	}
	return (rrange);
}

int	main(void)
{
	int	i;
	int	start;
	int	end;
	int	*rrange;

	start = 1;
	end = 1;
	rrange = ft_rrange(start, end);
	i = 0;
	while (i < end - start + 1)
	{
		printf("%d\n", rrange[i]);
		i++;
	}
}
