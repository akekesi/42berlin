/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:25:43 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/17 19:13:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strnstr(void);
static int	test_check(char *result, char *result_ft, int n);
char		*sof_strnstr(const char *s, const char *find, size_t slen);

int	test_ft_strnstr(void)
{
	const char	str_wm1[] = "lorem ipsum dolor sit amet";
	const char	str_wm2[] = "dolor";
	// const char	str_wm2[] = "lorem";
	// const char	str_wm2[] = "dol";
	// const char	str_wm2[] = "do\0lor";
	// const char	str_wm2[] = "sit";
	// const char	str_wm2[] = "ipsum";
	// const char	str_wm2[] = "";
	size_t		n;
	int			i;
	char		*result;
	char		*result_ft;

	i = 1;
	n = 15;
	// result = strnstr(str_wm1, str_wm2, n);
	result = sof_strnstr(str_wm1, str_wm2, n);
	result_ft = ft_strnstr(str_wm1, str_wm2, n);
	printf("result:    %s\n", result);
	printf("result_ft: %s\n", result_ft);
	if (!test_check(result, result_ft, i++))
		return (0);
	return (1);
}

static int	test_check(char *result, char *result_ft, int n)
{
	if (result != result_ft)
	{
		printf("Error-%d:\n", n);
		printf("result:    %s\n", result);
		printf("result_ft: %s\n", result_ft);
		return (0);
	}
	return (1);
}

char *sof_strnstr(const char *s, const char *find, size_t slen)
{
	/*
	https://opensource.apple.com/source/Libc/Libc-391.2.3/string/FreeBSD/strnstr.c.auto.html
	*/
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
