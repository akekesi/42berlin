/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:40:09 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 18:40:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_isdigit(void);
int	test_ft_isdigit_check(
		int c,
		int result_isdigit,
		int result_ft_isdigit);

int	test_ft_isdigit(void)
{
	int		n;
	int		result_isdigit;
	int		result_ft_isdigit;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_isdigit = isdigit(n);
		result_ft_isdigit = ft_isdigit(n);
		if (!test_ft_isdigit_check(n, result_isdigit, result_ft_isdigit))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_isdigit(): ");
	scanf("%c", &c);
	result_isdigit = isdigit(c);
	result_ft_isdigit = ft_isdigit(c);
	if (!test_ft_isdigit_check(c, result_isdigit, result_ft_isdigit))
		return (0);
	return (1);
}

int	test_ft_isdigit_check(
	int c,
	int result_isdigit,
	int result_ft_isdigit)
{
	if ((result_isdigit && !result_ft_isdigit)
		|| (!result_isdigit && result_ft_isdigit))
	{
		printf("Error:\n");
		printf("isdigit(%c):    %d\n", c, result_isdigit);
		printf("ft_isdigit(%c): %d\n", c, result_ft_isdigit);
		return (0);
	}
	return (1);
}
