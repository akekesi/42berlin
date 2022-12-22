/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 22:49:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strncmp(void);
static int	test_check(const char *str1, const char *str2, size_t n, int i);
static void	test_print(const char *str1, const char *str2, size_t n, int result, int result_ft);

int	test_ft_strncmp(void)
{
	const char	str1[] = "1234567";
	const char	str2[] = "123456X";
	const char	str3[] = "123";
	const char	str4[] = "";
	const char	str_wm1[] = "text_\200";
	const char	str_wm2[] = "text_\0";
	size_t		n;
	int			i;

	i = 1;
	n = 0;
	if (!test_check(str1, str2, n, i++))
		return (0);
	n = 1;
	if (!test_check(str1, str2, n, i++))
		return (0);
	n = 7;
	if (!test_check(str1, str2, n, i++))
		return (0);
	n = 8;
	if (!test_check(str1, str2, n, i++))
		return (0);
	n = 1;
	if (!test_check(str1, str3, n, i++))
		return (0);
	n = 3;
	if (!test_check(str1, str3, n, i++))
		return (0);
	n = 8;
	if (!test_check(str1, str3, n, i++))
		return (0);
	n = 8;
	if (!test_check(str1, str3, n, i++))
		return (0);
	n = 8;
	if (!test_check(str1, str4, n, i++))
		return (0);
	n = 8;
	if (!test_check(str4, str1, n, i++))
		return (0);
	n = 11;
	if (!test_check(str4, str4, n, i++))
		return (0);
	n = 6;
	if (!test_check(str_wm1, str_wm2, n, i++))
		return (0);
	return (1);
}

static int	test_check(const char *str1, const char *str2, size_t n, int i)
{
	int			result;
	int			result_ft;

	result = strncmp(str1, str2, n);
	result_ft = ft_strncmp(str1, str2, n);
	if (result != result_ft)
	{
		printf("Error-%d:\n", i);
		test_print(str1, str2, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str1, const char *str2, size_t n, int result, int result_ft)
{
	printf("strncmp(%s, %s, %lu):    %d\n", str1, str2, n, result);
	printf("strncmp_ft(%s, %s, %lu): %d\n", str1, str2, n, result_ft);
}