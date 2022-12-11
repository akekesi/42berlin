/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:39:18 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 18:39:18 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_isalnum(void);
int	test_ft_isalnum_check(
		int c,
		int result_isalnum,
		int result_ft_isalnum);

int	test_ft_isalnum(void)
{
	int		n;
	int		result_isalnum;
	int		result_ft_isalnum;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_isalnum = isalnum(n);
		result_ft_isalnum = ft_isalnum(n);
		if (!test_ft_isalnum_check(n, result_isalnum, result_ft_isalnum))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_isalnum(): ");
	scanf("%c", &c);
	result_isalnum = isalnum(c);
	result_ft_isalnum = ft_isalnum(c);
	if (!test_ft_isalnum_check(c, result_isalnum, result_ft_isalnum))
		return (0);
	return (1);
}

int	test_ft_isalnum_check(
	int c,
	int result_isalnum,
	int result_ft_isalnum)
{
	if ((result_isalnum && !result_ft_isalnum)
		|| (!result_isalnum && result_ft_isalnum))
	{
		printf("Error:\n");
		printf("isalnum(%c):    %d\n", c, result_isalnum);
		printf("ft_isalnum(%c): %d\n", c, result_ft_isalnum);
		return (0);
	}
	return (1);
}
