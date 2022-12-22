/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:03 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 20:46:20 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strlen(void);
static int	test_check(const char *str);
static void	test_print(const char *str, size_t result, size_t result_ft);

int	test_ft_strlen(void)
{
	const char	str[] = "123";

	if (!test_check(str))
		return (0);
	return (1);
}

static int	test_check(const char *str)
{
	size_t	result;
	size_t	result_ft;

	result = strlen(str);
	result_ft = ft_strlen(str);
	if (result != result_ft)
	{
		printf("Error:\n");
		test_print(str, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, size_t result, size_t result_ft)
{
	printf("strlen(%s):    %lu\n", str, result);
	printf("ft_strlen(%s): %lu\n", str, result_ft);
}
