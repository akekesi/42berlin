/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:11:31 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/02 13:11:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_check(int n, int n___)
{
	if (n == n___)
	{
		printf("OK ");
		test_print(n, n___, '=');
		return (1);
	}
	printf("NOK ");
	test_print(n, n___, '!');
	printf("^^^ ERROR^^^\n");
	return (0);
}

void	test_print(int n, int n___, int c)
{
	printf("%d %c= %d\n", n, c, n___);
}

void	test_print_flags_info(int *flags_info)
{
	int	i;

	i = 0;
	printf("\n(flags: ");
	while (i < 9)
	{
		printf("%d ", flags_info[i]);
		i++;
	}
	printf(" = |type|-|.|#| |+|0|9.|.9|)\n");
}

/*
#include <stdlib.h>

char	*get_str_malloc(void)
{
	char	*str;
	str = (char *)malloc(sizeof(char) * 6);
	str[0] = 'A'; 
	str[1] = 'B'; 
	str[2] = 'C';
	str[3] = '\0'; 
	return (str);
}

char	*get_str(void)
{
	return ("ABC");
}

void	replacechar(char *str, int i)
{
	*(str + i) = '\0';
}

int	main(void)
{
	char	*str;

	str = get_str_malloc();
	replacechar(str, 2);
	printf("%s\n", str);
	str = get_str();
	replacechar(str, 2);
	printf("%s\n", str);
}
*/