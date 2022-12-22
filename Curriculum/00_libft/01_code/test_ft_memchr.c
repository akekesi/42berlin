/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:09:48 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 20:44:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_memchr(void);
static int	test_check(const char *str, int c, size_t n);
static void	test_print(const char *str, int c, size_t n, char *result, char *result_ft);

int	test_ft_memchr(void)
{
	const char	str[] = "123x56";
	int			c;
	size_t		n;

	n = 5;
	c = 'x';
	if (!test_check(str, c, n))
		return (0);
	return (1);
}

static int	test_check(const char *str, int c, size_t n)
{
	char	*result;
	char	*result_ft;

	result = memchr(str, c, n);
	result_ft = ft_memchr(str, c, n);
	if (result != result_ft)
	{
		printf("Error:\n");
		test_print(str, c, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, int c, size_t n, char *result, char *result_ft)
{
	printf("memchr(%s, %c, %lu):    %p\n", str, c, n, result);
	printf("ft_memchr(%s, %c, %lu): %p\n", str, c, n, result_ft);
}
