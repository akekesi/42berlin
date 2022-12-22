/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:10:19 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 22:34:26 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_strchr(void);
static int	test_check(const char *str, int c, int i);
static void	test_print(const char *str, int c, char *result, char *result_ft);

int	test_ft_strchr(void)
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

	result = strchr(str, c);
	result_ft = ft_strchr(str, c);
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
	printf("strchr(%s, %c):    %p\n", str, c, result);
	printf("ft_strchr(%s, %c): %p\n", str, c, result_ft);
}
