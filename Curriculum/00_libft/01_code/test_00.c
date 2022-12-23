#include "stdio.h"

int	main(void)
{
	int		c;
	// char	str[] = "123";
	char	*str;

	c = '\0';
	if (c == 0)
		printf("equal\n");
	else
		printf("not equal\n");
	printf("'\\200': %d\n", '\200');

	str = NULL;
	str = "";
	if (str)
		printf("1");
	return (1);
}
