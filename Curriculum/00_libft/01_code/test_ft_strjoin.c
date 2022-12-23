/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 18:47:34 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strjoin(void);
static int	test_check(const char *str1, const char *str2);
static void	test_print(const char *str1, const char *str2, char *result, char *result_ft);
static char	*hf_ft_strjoin_arthur(char const *s1, char const *s2);

int	test_ft_strjoin(void)
{
	const char		str1[] = "Csak az ";
	const char		str2[] = "Old's!";

	if (!test_check(str1, str2))
		return (0);
	return (1);
}

static int	test_check(const char *str1, char const *str2)
{
	char	*result;
	char	*result_ft;

	result = hf_ft_strjoin_arthur(str1, str2);
	result_ft = ft_strjoin(str1, str2);
	if (strcmp(result, result_ft))
	{
		printf("Error:\n");
		test_print(str1, str2, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str1, const char *str2, char *result, char *result_ft)
{
	printf("strjoin(%s, %s):    -->%s<--\n", str1, str2, result);
	printf("ft_strjoin(%s, %s): -->%s<--\n", str1, str2, result_ft);
}

static char	*hf_ft_strjoin_arthur(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
