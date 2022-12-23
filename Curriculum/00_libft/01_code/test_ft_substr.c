/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 14:59:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_substr(void);
static int	test_check(const char *str, unsigned int start, size_t size);
static void	test_print(const char *str, unsigned int start, size_t size, char *result, char *result_ft);
static char	*hf_ft_substr_arthur(char const *s, unsigned int start, size_t len);

int	test_ft_substr(void)
{
	const char		str[] = "Csak az Old's!";
	unsigned int	start;
	size_t			len;

	start = 8;
	len = 5;
	if (!test_check(str, start, len))
		return (0);
	return (1);
}

static int	test_check(const char *str, unsigned int start, size_t len)
{
	char	*result;
	char	*result_ft;

	result = hf_ft_substr_arthur(str, start, len);
	result_ft = ft_substr(str, start, len);
	test_print(str, start, len, result, result_ft);
	if (strcmp(result, result_ft))
	{
		printf("Error:\n");
		test_print(str, start, len, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, unsigned int start, size_t len, char *result, char *result_ft)
{
	printf("substr(%s, %lu, %lu):    %s\n", str, start, len, result);
	printf("ft_substr(%s, %lu, %lu): %s\n", str, start, len, result_ft);
}

static char	*hf_ft_substr_arthur(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = malloc(sizeof(char));
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (++i - 1 < len)
		*(dst + i - 1) = *(s + start + i - 1);
	*(dst + i - 1) = '\0';
	return (dst);
}
