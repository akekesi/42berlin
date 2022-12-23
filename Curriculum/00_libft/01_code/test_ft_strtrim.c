/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:59 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 19:01:48 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_strtrim(void);
static int	test_check(const char *str, const char *set);
static void	test_print(const char *str, const char *set, char *result, char *result_ft);
static char	*hf_ft_strtrim_arthur(char const *s1, char const *set);
static int	hf_ft_char_in_set_arthur(char c, char const *set);

int	test_ft_strtrim(void)
{
	const char		str[] = "Csak az Old's!";
	const char		set[] = "zCs!'a k";

	if (!test_check(str, set))
		return (0);
	return (1);
}

static int	test_check(const char *str, char const *set)
{
	char	*result;
	char	*result_ft;

	result = hf_ft_strtrim_arthur(str, set);
	result_ft = ft_strtrim(str, set);
	if (strcmp(result, result_ft))
	{
		printf("Error:\n");
		test_print(str, set, result, result_ft);
		return (0);
	}
	return (1);
}

static void	test_print(const char *str, const char *set, char *result, char *result_ft)
{
	printf("strtrim(%s, %s):    -->%s<--\n", str, set, result);
	printf("ft_strtrim(%s, %s): -->%s<--\n", str, set, result_ft);
}

static char	*hf_ft_strtrim_arthur(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && hf_ft_char_in_set_arthur(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && hf_ft_char_in_set_arthur(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

static int	hf_ft_char_in_set_arthur(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
