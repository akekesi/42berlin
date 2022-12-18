/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:01:56 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/18 12:01:56 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int				test_ft_strlcpy(void);
static int		test_check(int result, int result_ft, char * dest, char *dest_ft, int n);
static size_t	sof_strlcpy(char *dst, const char *src, size_t siz);

int	test_ft_strlcpy(void)
{
	char		dest[] = "text_XX\200";
	char		dest_ft[] = "text_XX\200";
	const char	src[] = "text_\0";
	size_t		n;
	int			i;
	int			result;
	int			result_ft;

	i = 1;
	n = 0;
	// result = strlcpy(dest, src, n);
	result = sof_strlcpy(dest, src, n);
	result_ft = ft_strlcpy(dest_ft, src, n);
	if (!test_check(result, result_ft, dest, dest_ft, i++))
		return (0);
	return (1);
}

static int	test_check(int result, int result_ft, char * dest, char *dest_ft, int n)
{
	if ((result != result_ft) || strcmp(dest, dest_ft))
	{
		printf("Error-%d:\n", n);
		printf("result:    %d\n", result);
		printf("result_ft: %d\n", result_ft);
		printf("dest:    %s\n", dest);
		printf("dest_ft:    %s\n", dest_ft);
		return (0);
	}
	return (1);
}

static size_t	sof_strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
  }
	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}
	return(s - src - 1);	/* count does not include NUL */
}
