/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:39:50 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 18:39:50 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_isascii(void);
int	test_ft_isascii_check(
		int arg,
		int result_isascii,
		int result_ft_isascii);

int	test_ft_isascii(void)
{
	int		n;
	int		result_isascii;
	int		result_ft_isascii;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_isascii = isascii(n);
		result_ft_isascii = ft_isascii(n);
		if (!test_ft_isascii_check(n, result_isascii, result_ft_isascii))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_isascii(): ");
	scanf("%c", &c);
	result_isascii = isascii(c);
	result_ft_isascii = ft_isascii(c);
	if (!test_ft_isascii_check(c, result_isascii, result_ft_isascii))
		return (0);
	return (1);
}

int	test_ft_isascii_check(
	int arg,
	int result_isascii,
	int result_ft_isascii)
{
	if ((result_isascii && !result_ft_isascii)
		|| (!result_isascii && result_ft_isascii))
	{
		printf("Error:\n");
		printf("isascii(%c):    %d\n", arg, result_isascii);
		printf("ft_isascii(%c): %d\n", arg, result_ft_isascii);
		return (0);
	}
	return (1);
}
