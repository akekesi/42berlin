#include <stdio.h>

void	rush(int x, int y);

int	main(void)
{
	int	x;
	int	y;

	printf("x: ");
	scanf("%i", &x);
	printf("y: ");
	scanf("%i", &y);
	rush(x, y);
	return (0);
}
