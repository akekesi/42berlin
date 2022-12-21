/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:43:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/17 19:58:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_memcpy(void);
static int	test_check(char *dest_origin, char *dest, char *dest_ft, const char *src_origin, const char *src, const char *src_ft, size_t n);
static void	test_print(char *dest_origin, const char *src_origin, size_t n, char *result, char *result_ft);

int	test_ft_memcpy(void)
{
	const char	src[] = "123456";
	const char	src_ft[] = "123456";
	const char	src_origin[] = "123456";
	char		*dest;
	char		*dest_ft;
	char		*dest_origin;
	size_t		n;
	int			i;

	n = 3;
	i = 3;
	dest = (char *) src + i;
	dest_ft = (char *) src_ft + i;
	dest_origin = (char *) src_origin + i;
	if (!test_check(dest_origin, dest, dest_ft, src_origin, src, src_ft, n))
		return (0);
	return (1);
}

static int	test_check(char *dest_origin, char *dest, char *dest_ft, const char *src_origin, const char *src, const char *src_ft, size_t n)
{
	char	*result;
	char	*result_ft;

	result = memcpy(dest, src, n);
	result_ft = ft_memcpy(dest_ft, src_ft, n);
	if (strcmp(result, result_ft))
	{
		printf("Error:\n");
		test_print(dest_origin, src_origin, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(char *dest_origin, const char *src_origin, size_t n, char *result, char *result_ft)
{
	printf("memcpy(%s, %s, %d):    %s\n", dest_origin, src_origin, n, result);
	printf("ft_memcpy(%s, %s, %d): %s\n", dest_origin, src_origin, n, result_ft);
}
