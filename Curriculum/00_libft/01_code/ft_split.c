/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/24 23:32:48 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

char		**ft_split(char const *str, char const c);
static int	hf_count_words(char const *str, char const c);
static int	hf_len_word(char const *str, char const c, int i);
static void	hf_free_matrix(char **matrix);

char	**ft_split(char const *str, char const c)
{
	int		i;
	int		m;
	int		m_max;
	int		n;
	char	**strs;

	m_max = hf_count_words(str, c);
	strs = (char **)malloc(sizeof(char *) * (m_max + 1));
	if (!strs)
		return (NULL);
	i = 0;
	m = 0;
	while (m < m_max)
	{
		while (str[i] == c)
			i++;
		n = hf_len_word(str, c, i);
		strs[m] = ft_substr(str, i, n);
		if (!strs[m])
		{
			hf_free_matrix(strs);
			return (NULL);
		}
		i += n;
		m++;
	}
	strs[m] = NULL;
	return (strs);
}

static int	hf_count_words(char const *str, char const c)
{
	int	n;
	int	found;

	n = 0;
	found = 0;
	while (*str)
	{
		if (*str != c && !found)
		{
			n++;
			found = 1;
		}
		if (*str == c)
			found = 0;
		str++;
	}
	return (n);
}

static int	hf_len_word(char const *str, char const c, int i)
{
	int	n;

	n = 0;
	while (str[i] != c && str[i])
	{
		i++;
		n++;
	}
	return (n);
}

static void	hf_free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
