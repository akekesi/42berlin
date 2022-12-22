/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:01:56 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 20:22:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

// for strlcpy():
#include <bsd/string.h>
// but it works in external terminal (but not in vs code)
// compile and run:
// clear && gcc main.c ft_strlcpy.c test_ft_strlcpy.c ft_memcpy.c ft_strlen.c -lbsd && ./a.out

int			test_ft_strlcpy(void);
static int	test_check(char *dest_origin, char *dest, char *dest_ft, const char *src, size_t n);
static void	test_print(char *dest_origin, char *dest, char *dest_ft, const char *src, size_t n, size_t result, size_t result_ft);

int	test_ft_strlcpy(void)
{
	
	const char	src[] = "1234567890";
	int			len_dest;
	char		c;
	char		*dest;
	char		*dest_ft;
	char		*dest_origin;
	size_t		n;
	
	len_dest = 7;
	c = 'x';
	dest = (char *)malloc(sizeof(*dest) * len_dest);
	dest_ft = (char *)malloc(sizeof(*dest_ft) * len_dest);
	dest_origin = (char *)malloc(sizeof(*dest_ft) * len_dest);
	memset(dest, c, len_dest);
	memset(dest_ft, c, len_dest);
	memset(dest_origin, c, len_dest);

	n = 9;
	if (!test_check(dest_origin, dest, dest_ft, src, n))
		return (0);
	return (1);
}

static int	test_check(char *dest_origin, char *dest, char *dest_ft, const char *src, size_t n)
{
	size_t	result;
	size_t	result_ft;

	result = strlcpy(dest, src, n);
	result_ft = ft_strlcpy(dest_ft, src, n);
	if (result != result_ft)
	{
		printf("Error:\n");
		test_print(dest_origin, dest, dest_ft, src, n, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(char *dest_origin, char *dest, char *dest_ft, const char *src, size_t n, size_t result, size_t result_ft)
{
	printf("strlcpy(%s, %s, %lu):    %p --> %s --> %lu\n", dest_origin, src, n, dest, dest, result);
	printf("ft_strlcpy(%s, %s, %lu): %p --> %s --> %lu\n", dest_origin, src, n, dest_ft, dest_ft, result_ft);
}
