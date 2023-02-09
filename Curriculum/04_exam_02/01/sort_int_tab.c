/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

#include <stdio.h>

void	ft_print_list(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!size)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	tab[] = {99, -1, 0, -1, -11, 10, 0, 99, 100, 1111, -1111};
	int	size = 11;

	ft_print_list(tab, size);
	printf("\n");
	sort_int_tab(tab, size);
	ft_print_list(tab, size);
}
