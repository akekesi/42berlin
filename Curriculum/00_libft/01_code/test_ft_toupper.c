/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:45:00 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 21:45:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include "test.h"

int	test_ft_toupper(void);
int	test_ft_toupper_check(
		int arg,
		int result_toupper,
		int result_ft_toupper);

int	test_ft_toupper(void)
{
	int		n;
	int		result_toupper;
	int		result_ft_toupper;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_toupper = toupper(n);
		result_ft_toupper = ft_toupper(n);
		if (!test_ft_toupper_check(n, result_toupper, result_ft_toupper))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_toupper(): ");
	scanf("%c", &c);
	result_toupper = toupper(c);
	result_ft_toupper = ft_toupper(c);
	if (!test_ft_toupper_check(c, result_toupper, result_ft_toupper))
		return (0);
	return (1);
}

int	test_ft_toupper_check(
	int arg,
	int result_toupper,
	int result_ft_toupper)
{
	if ((result_toupper && !result_ft_toupper)
		|| (!result_toupper && result_ft_toupper))
	{
		printf("Error:\n");
		printf("toupper(%c):    %d\n", arg, result_toupper);
		printf("ft_toupper(%c): %d\n", arg, result_ft_toupper);
		return (0);
	}
	return (1);
}
