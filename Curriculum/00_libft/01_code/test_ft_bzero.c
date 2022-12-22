/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:11 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/12 11:12:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_bzero(void);
static int	test_check(char *str_origin, char *str, char *str_ft, size_t n);
static void	test_print(char *str_origin, char *str, char *str_ft, size_t n);

int	test_ft_bzero(void)
{
	char	str[] = "123";
	char	str_ft[] = "123";
	char	str_origin[] = "123";
	size_t	n;

	n = 2;
	if (!test_check(str_origin, str, str_ft, n))
		return (0);
	return (1);
}

static int	test_check(char *str_origin, char *str, char *str_ft, size_t n)
{
	memset(str, '\0', n);
	ft_bzero(str_ft, n);
	if (strcmp(str, str_ft))
	{
		printf("Error:\n");
		test_print(str_origin, str, str_ft, n);
		return (0);
	}
	return (1);
}

static void	test_print(char *str_origin, char *str, char *str_ft, size_t n)
{
	printf("bzero(%s, %lu):    %s\n", str_origin, n, str);
	printf("ft_bzero(%s, %lu): %s\n", str_origin, n, str_ft);
}
