/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:34:50 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 00:25:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_atoi(void);
static int	test_check(const char *str, int i);
static void	test_print(const char *str, int result, int result_ft);

int	test_ft_atoi(void)
{
	const char	str[] = " -12 3";
	int			i;

	i = 1;
	if (!test_check(str, i++))
		return (0);
}

static int	test_check(const char *str, int i)
{
	int	result;
	int	result_ft;

	result = atoi(str);
	result_ft = ft_atoi(str);
	if (result != result_ft)
	{
		printf("Error-%d:\n", i);
		test_print(str, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, int result, int result_ft)
{
	printf("atoi(%s):    %d\n", str, result);
	printf("ft_atoi(%s): %d\n", str, result_ft);
}
