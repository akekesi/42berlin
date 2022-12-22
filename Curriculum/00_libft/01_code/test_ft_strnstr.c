/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:25:43 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 23:20:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

// for strnstr():
#include <bsd/string.h>
// but it works in external terminal (but not in vs code)
// compile and run:
// clear && gcc main.c ft_strnstr.c test_ft_strnstr.c ft_strlen.c -lbsd && ./a.out

int			test_ft_strnstr(void);
static int	test_check(const char *str1, const char *str2, size_t n);
static void	test_print(const char *str1, const char *str2, size_t n, char *result, char *result_ft);

int	test_ft_strnstr(void)
{
	const char	str1[] = "lorem ipsum dolor sit amet";
	const char	str2[] = "dolor";
	// const char	str2[] = "lorem";
	// const char	str2[] = "dol";
	// const char	str2[] = "do\0lor";
	// const char	str2[] = "sit";
	// const char	str2[] = "ipsum";
	// const char	str2[] = "";
	size_t		n;
	
	n = 15;
	if (!test_check(str1, str2, n))
		return (0);
	return (1);
}

static int	test_check(const char *str1, const char *str2, size_t n)
{
	char		*result;
	char		*result_ft;

	result = strnstr(str1, str2, n);
	result_ft = ft_strnstr(str1, str2, n);
	if (result != result_ft)
	{
		printf("Error:\n");
		test_print(str1, str2, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str1, const char *str2, size_t n, char *result, char *result_ft)
{
	printf("strnstr(%s, %s, %lu):    %s\n", str1, str2, n, result);
	printf("ft_strnstr(%s, %s, %lu): %s\n", str1, str2, n, result_ft);
}
