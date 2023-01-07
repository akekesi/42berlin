/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:11:31 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 22:02:45 by akekesi          ###   ########.fr       */
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

void	test_print_flags_info(t_flag_info *flag_info)
{
	int	i;

	i = 0;
	printf("\nflags:\n");
	printf("-type:    %c\n", flag_info->type);
	printf("-minus:   %d\n", flag_info->minus);
	printf("-dot:     %d\n", flag_info->dot);
	printf("-hashtag: %d\n", flag_info->hashtag);
	printf("-space:   %d\n", flag_info->space);
	printf("-plus:    %d\n", flag_info->plus);
	printf("-zero:    %d\n", flag_info->zero);
	printf("-int_b:   %d\n", flag_info->int_b);
	printf("-int_a:   %d\n", flag_info->int_a);
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
