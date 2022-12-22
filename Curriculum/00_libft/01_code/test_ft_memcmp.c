/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:27:01 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 13:27:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_memcmp(void);
static int	test_check(const char *str1, const char *str2, size_t n);
static void	test_print(const char *str1, const char *str2, size_t n, int result, int result_ft);

int	test_ft_memcmp(void)
{
	const char	str1[] = "123x56";
	const char	str2[] = "123456";
	size_t		n;

	n = 5;
	if (!test_check(str1, str2, n))
		return (0);
	return (1);
}

static int	test_check(const char *str1, const char *str2, size_t n)
{
	int	result;
	int	result_ft;

	result = memcmp(str1, str2, n);
	result_ft = ft_memcmp(str1, str2, n);
	if (result != result_ft)
	{
		printf("Error:\n");
		test_print(str1, str2, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str1, const char *str2, size_t n, int result, int result_ft)
{
	printf("memcmp(%s, %s, %d):    %d\n", str1, str2, n, result);
	printf("ft_memcmp(%s, %s, %d): %d\n", str1, str2, n, result_ft);
}
