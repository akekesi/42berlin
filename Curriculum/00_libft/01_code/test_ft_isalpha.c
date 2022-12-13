/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:39:29 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:08:04 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_isalpha(void);
int	test_ft_isalpha_check(
		int c,
		int result_isalpha,
		int result_ft_isalpha);

int	test_ft_isalpha(void)
{
	int		n;
	int		result_isalpha;
	int		result_ft_isalpha;
	char	c;

	n = 0;
	while (n < 128)
	{
		result_isalpha = isalpha(n);
		result_ft_isalpha = ft_isalpha(n);
		if (!test_ft_isalpha_check(n, result_isalpha, result_ft_isalpha))
			return (0);
		n++;
	}
	printf("Enter a character to test ft_isalpha(): ");
	scanf("%c", &c);
	result_isalpha = isalpha(c);
	result_ft_isalpha = ft_isalpha(c);
	if (!test_ft_isalpha_check(c, result_isalpha, result_ft_isalpha))
		return (0);
	return (1);
}

int	test_ft_isalpha_check(
	int c,
	int result_isalpha,
	int result_ft_isalpha)
{
	if ((result_isalpha && !result_ft_isalpha)
		|| (!result_isalpha && result_ft_isalpha))
	{
		printf("Error:\n");
		printf("isalpha(%c):    %d\n", c, result_isalpha);
		printf("ft_isalpha(%c): %d\n", c, result_ft_isalpha);
		return (0);
	}
	return (1);
}
