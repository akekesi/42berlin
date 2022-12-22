/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:25:58 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 20:45:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_memset(void);
static int	test_check(char *str, char *str_ft, int c, size_t n);
static void	test_print(char *str, char *str_ft, int c, size_t n, char *result, char *result_ft);

int	test_ft_memset(void)
{
	int		c;
	char	str[] = "123";
	char	str_ft[] = "123";
	size_t	n;

	n = 2;
	c = 'X';
	if (!test_check(str, str_ft, c, n))
		return (0);
	return (1);
}

static int	test_check(char *str, char *str_ft, int c, size_t n)
{
	char	*result;
	char	*result_ft;

	result = memset(str, c, n);
	result_ft = ft_memset(str_ft, c, n);
	if (strcmp(result, result_ft))
	{
		printf("Error:\n");
		test_print(str, str_ft, c, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(char *str, char *str_ft, int c, size_t n, char *result, char *result_ft)
{
	printf("memset(%s, %c, %lu):    %s\n", str, c, n, result);
	printf("ft_memset(%s, %c, %lu): %s\n", str_ft, c, n, result_ft);
}
