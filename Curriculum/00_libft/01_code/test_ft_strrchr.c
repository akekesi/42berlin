/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:34:11 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 22:34:24 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_strrchr(void);
static int	test_check(const char *str, int c, int i);
static void	test_print(const char *str, int c, char *result, char *result_ft);

int	test_ft_strrchr(void)
{
	int		i;
	int		c;
	char	str[] = "012X45";

	i = 1;
	c = 'X';
	if (!test_check(str, c, i++))
		return (0);
	c = '!';
	if (!test_check(str, c, i++))
		return (0);
	c = '\0';
	if (!test_check(str, c, i++))
		return (0);
	c = '\0';
	str[0] = '\0';
	if (!test_check(str, c, i++))
		return (0);
	return (1);
}

static int	test_check(const char *str, int c, int i)
{
	char	*result;
	char	*result_ft;

	result = strrchr(str, c);
	result_ft = ft_strrchr(str, c);
	if (result != result_ft)
	{
		printf("Error-%d:\n", i);
		test_print(str, c, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, int c, char *result, char *result_ft)
{
	printf("strrchr(%s, %c):    %p\n", str, c, result);
	printf("ft_strrchr(%s, %c): %p\n", str, c, result_ft);
}
