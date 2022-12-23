/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 21:59:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			**ft_strsplit(char const *str, char c);
static size_t	hf_calc_substr(char const *str, char c);
static char		*hf_find_other(char const *str, char c);
static size_t	hf_len_other(char const *str, char c);

char	**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	n;
	char	**strs;
	char	*start;
	size_t	len;

	n = hf_calc_substr(str, c);
	printf("n: %d\n", n);
	strs = (char **)malloc(sizeof(char *) * n + 1);
	if (!strs)
		return (NULL);
	i = 0;
	while (i < n)
	{
		start = hf_find_other(str, c);
		len = hf_len_other(start, c);
		printf("%s - %lu\n", start, len);
		strs[i] = (char *)malloc(sizeof(char) * 2);
		if (!strs[i])
		{
			// hf_free2dchar(strs); !!! FREE !!!
			return (NULL);
		}
		strs[i][0] = '0' + i;
		strs[i][1] = '\0';
		i++;
	}
	strs[n] = NULL;
	return (strs);
}

static size_t	hf_calc_substr(char const *str, char c)
{
	size_t	i;
	size_t	n;
	size_t	prev;

	i = 0;
	n = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] == c && prev)
		{
			n++;
			printf("%d. %d --> %d\n", n, i - prev, prev);
			prev = 0;
		}
		if (str[i] != c)
			prev++;
		i++;
	}
	if (prev)
	{
		n++;
		printf("%d. %d --> %d\n", n, i - prev, prev);
	}
	return (n);
}

static char	*hf_find_other(char const *str, char c)
{
	while (*str == c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}

static size_t	hf_len_other(char const *str, char c)
{
	size_t	n;

	n = 0;
	while (str[n] != c && str[n])
		n++;
	return (n);
}

int	main(void)
{
	char const	str[] = "xx1x123x12345x12xx ";
	char		c;
	size_t		i;
	char		**strs;
	c = 'x';
	strs = ft_strsplit(str, c);
	i = 0;
	while (strs[i])
	{
		printf("%d. -->%s<--\n", i, strs[i]);
		i++;
	}

	return (0);
}
