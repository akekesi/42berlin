/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:40:18 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 18:40:18 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_isprint(void);
int	test_ft_isprint_check(
		int arg,
		int result_isprint,
		int result_ft_isprint);

int	test_ft_isprint(void)
{
	int		n;
	int		result_isprint;
	int		result_ft_isprint;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_isprint = isprint(n);
		result_ft_isprint = ft_isprint(n);
		if (!test_ft_isprint_check(n, result_isprint, result_ft_isprint))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_isprint(): ");
	scanf("%c", &c);
	result_isprint = isprint(c);
	result_ft_isprint = ft_isprint(c);
	if (!test_ft_isprint_check(c, result_isprint, result_ft_isprint))
		return (0);
	return (1);
}

int	test_ft_isprint_check(
	int arg,
	int result_isprint,
	int result_ft_isprint)
{
	if ((result_isprint && !result_ft_isprint)
		|| (!result_isprint && result_ft_isprint))
	{
		printf("Error:\n");
		printf("isprint(%c):    %d\n", arg, result_isprint);
		printf("ft_isprint(%c): %d\n", arg, result_ft_isprint);
		return (0);
	}
	return (1);
}
