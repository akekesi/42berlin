#include "stdio.h"
#include <stdlib.h>

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
	// -------------
	char	*ptr_char;
	ptr_char = (char *)malloc(0);
	printf("%p --> ***%c***\n", ptr_char, *ptr_char + 'A');
	char	*ptr_void;
	ptr_void = malloc(0);
	printf("%p --> ***%c***\n", ptr_void, *ptr_void + 'B');
	// -------------

	return (1);
}
