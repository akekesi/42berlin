/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 21:10:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_striteri(void);
static int	test_check(char *str, char *str_, int i);
static void	test_func(unsigned int i, char *c);
static void	test_print(char *str, char *result, char *result_ft);

int	test_ft_striteri(void)
{
	char	str1[] = "";
	char	str1_[] = "";
	char	str2[] = "0";
	char	str2_[] = "1";
	char	str3[] = "123";
	char	str3_[] = "234";
	char	str4[] = "\t";
	char	str4_[] = "\n";
	char	str5[] = "9(";
	char	str5_[] = ":)";
	char	str6[] = "abc\0xxx";
	char	str6_[] = "bcd";
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

static int	test_check(char *str, char *str_, int i)
{
	char	*result;
	char	*result_ft;

	result = str_;
	ft_striteri(str, test_func);
	result_ft = str;
	if (strcmp(result, result_ft))
	{
		printf("Error-%d:\n", i);
		test_print(str, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_func(unsigned int i, char *c)
{
	*c += 1;
}

static void	test_print(char *str, char *result, char *result_ft)
{
	printf("striteri(%s, f):    -->%s<--\n", str, result);
	printf("striteri_ft(%s, f): -->%s<--\n", str, result_ft);
}
