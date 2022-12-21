/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:40:09 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:07:51 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_isdigit(void);
static int	test_check(int c);
static void	test_print(int c, int result, int result_ft);

int	test_ft_isdigit(void)
{
	int		c;

	c = 0;
	while (c < 128)
	{
		if (!test_check(c))
			return (0);
		c++;
	}
	c = '\0';
	if (!test_check(c))
		return (0);
	return (1);
}

int	test_check(int c)
{
	int		result;
	int		result_ft;

	result = isdigit(c);
	result_ft = ft_isdigit(c);
	if ((result && !result_ft)
		|| (!result && result_ft))
	{
		printf("Error:\n");
		test_print(c, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(int c, int result, int result_ft)
{
	printf("isdigit(%c):    %d\n", c, result);
	printf("ft_isdigit(%c): %d\n", c, result_ft);
}
