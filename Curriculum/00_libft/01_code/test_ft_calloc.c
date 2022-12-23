/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:59:25 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 01:59:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_calloc(void);
static int	test_check(size_t n, size_t size, int i);
static int	test_print(size_t n, size_t size, void *result, void *result_ft);

int	test_ft_calloc(void)
{
	int		i;
	size_t	n;
	size_t	size;

	i = 1;
	n = 6;
	size = 6;
	if (!test_check(n, size, i++))
		return (0);
	return (1);
}

static int	test_check(size_t n, size_t size, int i)
{
	 void *result;
	 void *result_ft;

	 result = calloc(n, size);
	 result_ft = ft_calloc(n, size);
	 if (memcmp(result, result_ft, n * size))
	 {
		printf("Error-%d", i);
		test_print(n, size, result, result_ft);
	 	return (0);
	 }
	return (1);
}

static int	test_print(size_t n, size_t size, void *result, void *result_ft)
{
	printf("calloc(%lu, %lu):    %p\n", n, size, result);
	printf("ft_calloc(%lu, %lu): %p\n", n, size, result_ft);
}
