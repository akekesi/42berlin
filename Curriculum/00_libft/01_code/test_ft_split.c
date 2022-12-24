/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:03:09 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/24 23:32:50 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int			test_ft_split(void);
static int	test_check(char const *str, char const c);
static void	test_print(char const *str, char const c, char **result, char **result_ft);
static void	ft_free_taka(char **str, int j);
static int	ft_word_size_taka(char const *s, char c, int i);
static int	ft_wdcount_taka(char const *str, char c);
static char	**ft_split_taka(char const *str, char const c);


int	test_ft_split(void)
{
	char	const 	str[] = "Csak az Old's!";
	char	const 	c = ' ';

	if (!test_check(str, c))
		return (0);
	return (1);
}

static int	test_check(char const *str, char const c)
{
	int	i;
	char	**result;
	char	**result_ft;

	result = ft_split_taka(str, c);
	result_ft = ft_split(str, c);
	i = 0;
	while (result[i] != NULL && result_ft[i] != NULL)
	{
		if (strcmp(result[i], result_ft[i]))
		{
			printf("Error:\n");
			test_print(str, c, result, result_ft);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	test_print(char const *str, char const c, char **result, char **result_ft)
{
	int	i;

	i = 0;
	while (result[i] != NULL && result_ft[i] != NULL)
	{
		printf("split(%s, %c):    -->%s<--\n", str, c, result[i]);
		printf("ft_split(%s, %c): -->%s<--\n", str, c, result_ft[i]);
		i++;
	}
}

static int	ft_wdcount_taka(char const *str, char c)
{
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static int	ft_word_size_taka(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free_taka(char **str, int j)
{
	while (j > -1)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static char	**ft_split_taka(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**str;

	i = 0;
	j = 0;
	word = ft_wdcount_taka(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_word_size_taka(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
		{
			ft_free_taka(str, j);
			return (NULL);
		}
		i = size + i;
		j++;
	}
	str[j] = NULL;
	return (str);
}
