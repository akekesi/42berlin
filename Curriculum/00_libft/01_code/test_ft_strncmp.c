/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/16 15:16:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strncmp(void);
static int	test_check(int result, int result_ft, int n);

int	test_ft_strncmp(void)
{
	char	str1[] = "1234567";
	char	str2[] = "123456X";
	char	str3[] = "123";
	char	str4[] = "";
	char	str_wm1[] = "text_\200";
	char	str_wm2[] = "text_\0";
	int		n;
	int		i;
	int		result;
	int		result_ft;

	i = 1;
	n = 0;
	result = strncmp(str1, str2, n);
	result_ft = ft_strncmp(str1, str2, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 1;
	result = strncmp(str1, str2, n);
	result_ft = ft_strncmp(str1, str2, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 7;
	result = strncmp(str1, str2, n);
	result_ft = ft_strncmp(str1, str2, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str1, str2, n);
	result_ft = ft_strncmp(str1, str2, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 1;
	result = strncmp(str1, str3, n);
	result_ft = ft_strncmp(str1, str3, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 3;
	result = strncmp(str1, str3, n);
	result_ft = ft_strncmp(str1, str3, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str1, str3, n);
	result_ft = ft_strncmp(str1, str3, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str1, str3, n);
	result_ft = ft_strncmp(str1, str3, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str1, str4, n);
	result_ft = ft_strncmp(str1, str4, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str4, str1, n);
	result_ft = ft_strncmp(str4, str1, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 11;
	result = strncmp(str4, str4, n);
	result_ft = ft_strncmp(str4, str4, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	n = 6;
	result = strncmp(str_wm1, str_wm2, n);
	result_ft = ft_strncmp(str_wm1, str_wm2, n);
	if (!test_check(result, result_ft, i++))
		return (0);
	return (1);
}

static int	test_check(int result, int result_ft, int n)
{
	if (result != result_ft)
	{
		printf("Error-%d:\n", n);
		printf("result:    %d\n", result);
		printf("result_ft: %d\n", result_ft);
		return (0);
	}
	return (1);
}
