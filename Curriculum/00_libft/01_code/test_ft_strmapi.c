/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 20:45:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strmapi(void);
static int	test_check(char const *str, char const *str_, int i);
static char	test_func(unsigned int i, char c);
static void	test_print(char const *str, char const *result, char *result_ft);

int	test_ft_strmapi(void)
{
	const char	str1[] = "";
	const char	str1_[] = "";
	const char	str2[] = "0";
	const char	str2_[] = "1";
	const char	str3[] = "123";
	const char	str3_[] = "234";
	const char	str4[] = "\t";
	const char	str4_[] = "\n";
	const char	str5[] = "9(";
	const char	str5_[] = ":)";
	const char	str6[] = "abc\0xxx";
	const char	str6_[] = "bcd";
	int			i;

	i = 1;
	if (!test_check(str1, str1_, i++))
		return (0);
	if (!test_check(str2, str2_, i++))
		return (0);
	if (!test_check(str3, str3_, i++))
		return (0);
	if (!test_check(str4, str4_, i++))
		return (0);
	if (!test_check(str5, str5_, i++))
		return (0);
	if (!test_check(str6, str6_, i++))
		return (0);
	return (1);
}

static int	test_check(char const *str, char const *str_, int i)
{
	char const	*result;
	char		*result_ft;

	result = str_;
	result_ft = ft_strmapi(str, test_func);
	if (strcmp(result, result_ft))
	{
		printf("Error-%d:\n", i);
		test_print(str, result, result_ft);
		return (0);
	}
	return (1);
}

static char	test_func(unsigned int i, char c)
{
	return (c + 1);
}

static void	test_print(char const *str, char const *result, char *result_ft)
{
	printf("strmapi(%s, f):    -->%s<--\n", str, result);
	printf("strmapi_ft(%s, f): -->%s<--\n", str, result_ft);
}
