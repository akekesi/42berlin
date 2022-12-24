/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 23:15:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
clear && gcc ft_strsplit.c && ./a.out
e
1. 2 --> 1
u
e
2. 4 --> 3
u
e
Fatal glibc error: malloc assertion failure in sysmalloc: (old_top == initial_top (av) && old_size == 0) || ((unsigned long) (old_size) >= MINSIZE && prev_inuse (old_top) && ((unsigned long) old_end & (pagesize - 1)) == 0)
Aborted (core dumped)
*/

// 1. test hogy 2d array-jel mukodne-e (hard coded)
// 2. 2d array 2 lepesben eloallitani
// --> a hosszt meghatarozni
// --> feltolteni ertekekkel
// 3. dinamikus 2d array eloallitasa
// --> lehet ide a memoriabol atmasolas lenne a jo megoldas

#include "libft.h"
#include <stdio.h>

char			**ft_strsplit(char const *str, char c);
static size_t	**hf_calc_substr(char const *str, char c);
static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n);
static void		hf_free_2d(size_t **array);

char	**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	**pos_len;
	char	**strs;
	char	*start;
	size_t	n;

	pos_len = hf_calc_substr(str, c);
	// printf("n: %lu\n", n);
	n = 5;
	strs = (char **)malloc(sizeof(char *) * n + 1);
	if (!strs)
		return (NULL);
	i = 0;
	while (i < n)
	{
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

static size_t	**hf_calc_substr(char const *str, char c)
{
	size_t	i;
	size_t	n;
	size_t	prev;
	size_t	*row;
	size_t	**pos_len;


	pos_len = (size_t **)malloc(sizeof(size_t *) * 1);
	if (!pos_len)
		return (NULL);
	pos_len[0] = NULL;

	i = 0;
	n = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] == c && prev)
		{
			printf("*%lu\n", i);
			n++;
			row = (size_t *)malloc(sizeof(size_t) * 2);
			if (!row)
			{
				printf("NULL\n");
				return (NULL);
			}
			row[0] = i - prev;
			row[1] = prev;
			printf("e\n");
			pos_len = hf_add_row(pos_len, row, n);
			printf("%lu. %lu --> %lu\n", n, i - prev, prev);
			printf("u\n");
			prev = 0;
		}
		if (str[i] != c)
			prev++;
		i++;
	}
	if (prev)
	{
		n++;
		row = (size_t *)malloc(sizeof(size_t) * 2);
		if (!row)
			return (NULL);
		row[0] = i - prev;
		row[1] = prev;
		// pos_len = hf_add_row(pos_len, row, n);
		printf("%lu. %lu --> %lu\n", n, i - prev, prev);
	}
	return (pos_len);
}

static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n)
{
	size_t	i;
	size_t	**matrix_new;

	// printf("%lu\n", n);
	matrix_new = (size_t **)malloc(sizeof(size_t *) * (n + 1));
	if (!matrix_new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		matrix_new[i] = (size_t *)malloc(sizeof(size_t) * 2);
		if (!matrix_new[i])
			return (NULL);
		if (1 < n)
		{
			matrix_new[i][0] = matrix_old[i][0];
			printf("%lu\n", n);
			matrix_new[i][1] = matrix_old[i][1];
		}
		i++;
	}
	matrix_new[i][0] = row_new[0];
	matrix_new[i][1] = row_new[1];
	matrix_new[n + 1] = NULL;
	// hf_free_2d(matrix_old); // lehet csak free(matrix_old) kene, mert a tobbit hasznaljuk tovabb ???
	return (matrix_new);
}

static void	hf_free_2d(size_t **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
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
		printf("%lu. -->%s<--\n", i, strs[i]);
		i++;
	}

	return (0);
}
