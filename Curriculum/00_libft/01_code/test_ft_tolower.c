/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:49:00 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 21:49:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_tolower(void);
int	test_ft_tolower_check(
		int arg,
		int result_tolower,
		int result_ft_tolower);

int	test_ft_tolower(void)
{
	int		n;
	int		result_tolower;
	int		result_ft_tolower;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_tolower = tolower(n);
		result_ft_tolower = ft_tolower(n);
		if (!test_ft_tolower_check(n, result_tolower, result_ft_tolower))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_tolower(): ");
	scanf("%c", &c);
	result_tolower = tolower(c);
	result_ft_tolower = ft_tolower(c);
	if (!test_ft_tolower_check(c, result_tolower, result_ft_tolower))
		return (0);
	return (1);
}

int	test_ft_tolower_check(
	int arg,
	int result_tolower,
	int result_ft_tolower)
{
	if ((result_tolower && !result_ft_tolower)
		|| (!result_tolower && result_ft_tolower))
	{
		printf("Error:\n");
		printf("tolower(%c):    %d\n", arg, result_tolower);
		printf("ft_tolower(%c): %d\n", arg, result_ft_tolower);
		return (0);
	}
	return (1);
}
