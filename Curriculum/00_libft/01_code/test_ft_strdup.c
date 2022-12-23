/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:51:21 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 02:51:21 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strdup(void);
static int	test_check(const char *str, int i);
static int	test_print(const char *str, char *result, char *result_ft);

int	test_ft_strdup(void)
{
	int			i;
	const char	str[] = "123";

	i = 1;
	if (!test_check(str, i++))
		return (0);
	return (1);
}

static int	test_check(const char *str, int i)
{
	 char *result;
	 char *result_ft;

	 result = strdup(str);
	 result_ft = ft_strdup(str);
	 if (strcmp(result, result_ft))
	 {
		printf("Error-%d", i);
		test_print(str, result, result_ft);
	 	return (0);
	 }
	return (1);
}

static int	test_print(const char *str, char *result, char *result_ft)
{
	printf("strdup(%s):    %s\n", str, result);
	printf("ft_strdup(%s): %s\n", str, result_ft);
}
