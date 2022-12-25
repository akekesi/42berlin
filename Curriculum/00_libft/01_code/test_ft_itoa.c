/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:34:50 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 18:49:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_itoa(void);
static int	test_check(int n, int i);
static void	test_print(int n, int result, char *result_ft);

int	test_ft_itoa(void)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	if (!test_check(n, i++))
		return (0);
	n = 123;
	if (!test_check(n, i++))
		return (0);
	n = -123;
	if (!test_check(n, i++))
		return (0);
	n = 2147483647;
	if (!test_check(n, i++))
		return (0);
	n = -2147483647 - 1;
	if (!test_check(n, i++))
		return (0);
	n = -2147483648;
	if (!test_check(n, i++))
		return (0);
	return (1);
}

static int	test_check(int n, int i)
{
	int		result;
	char	*result_ft;

	result_ft = ft_itoa(n);
	result = atoi(result_ft);
	if (result != n)
	{
		printf("Error-%d:\n", i);
		test_print(n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(int n, int result, char *result_ft)
{
	printf("itoa(%d):    %d\n", n, result);
	printf("ft_itoa(%d): %s\n", n, result_ft);
}
