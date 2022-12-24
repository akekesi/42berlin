/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/24 16:45:24 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
!!! free memories if malloc returns NULL !!!
*/

#include "libft.h"
#include <stdio.h>

char			**ft_split(char const *str, char c);
static size_t	**hf_calc_substr(char const *str, char c);
static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n);
static size_t	hf_len_array(size_t **matrix);
static char		**hf_free_matrix_char(char **matrix);
static size_t	**hf_free_matrix_size_t(size_t **matrix, size_t m);

char	**ft_split(char const *str, char c)
{
	size_t	i;
	// size_t	j;
	size_t	m;
	size_t	**pos_len;
	char	**strs;

	if (!str)
		return (NULL);
	pos_len = hf_calc_substr(str, c);
	if (!pos_len)
	{
		// free ???
		return (NULL);
	}
	m = hf_len_array(pos_len);
	strs = (char **)malloc(sizeof(char *) * (m + 1));
	if (!strs)
	{
		// free ???
		return (NULL);
	}
	// printf("pos_len: %p --> %p\n", pos_len, *pos_len);
	i = 0;
	while (i < m)
	{
		// printf("%p: %lu --> %lu\n", pos_len[i], (pos_len[i])[0], (pos_len[i])[1]);
		strs[i] = (char *)malloc(sizeof(char) * (pos_len[i][1] + 1));
		if (!strs[i])
		{
			hf_free_matrix_char(strs);
			return (NULL);
		}
		strs[i] = ft_memcpy(strs[i], str + pos_len[i][0], pos_len[i][1]);
		strs[i][pos_len[i][1]] = '\0';
		// printf(" |%lu| ", strlen(strs[i]));
		// printf("-->");
		// j = 0;
		// while (j < pos_len[i][1])
		// {
		// 	printf("%c", *(str + pos_len[i][0]) + j);
		// 	j++;
		// }
		// printf("<--\n");
		i++;
	}
	strs[m] = NULL;
	pos_len = hf_free_matrix_size_t(pos_len, m);
	return (strs);
}

static size_t	**hf_calc_substr(char const *str, char c)
{
	size_t	i;
	size_t	n;
	size_t	prev;
	size_t	*row;
	size_t	**pos_len;

	i = 0;
	n = 0;
	prev = 0;
	pos_len = (size_t **)malloc(sizeof(size_t *) * 1);
	pos_len[0] = NULL;
	while (str[i])
	{
		if (str[i] == c && prev)
		{
			n++;
			// printf("%lu. %lu --> %lu\n", n, i - prev, prev);
			row = (size_t *)malloc(sizeof(size_t) * 2);
			if (!row)
			{
				// free ???
				return (NULL);
			}
			row[0] = i - prev;
			row[1] = prev;
			pos_len = hf_add_row(pos_len, row, n);
			// printf("%lu. %lu --> %lu --> %p\n", n, row[0], row[1], row);
			prev = 0;
		}
		if (str[i] != c)
			prev++;
		i++;
	}
	if (prev)
	{
		n++;
		// printf("%lu. %lu --> %lu\n", n, i - prev, prev);
		row = (size_t *)malloc(sizeof(size_t) * 2);
		if (!row)
		{
			// free ???
			return (NULL);
		}
		row[0] = i - prev;
		row[1] = prev;
		pos_len = hf_add_row(pos_len, row, n);
		// printf("%lu. %lu --> %lu --> %p\n", n, row[0], row[1], row);
	}
	// printf("pos_len: %p --> %p\n", pos_len, *pos_len);
	return (pos_len);
}

static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n)
{
	size_t	i;
	size_t	**matrix_new;

	matrix_new = (size_t **)malloc(sizeof(size_t *) * (n + 1));
	if (!matrix_new)
	{
		// free ???
		return (NULL);
	}
	i = 0;
	// printf("matrix_old:    %p\n", matrix_old);
	// printf("matrix_old[%lu]: %p\n", i, matrix_old[i]);
	while (i < n && matrix_old[i])
	{
		// printf("matrix_new:    %p\n", matrix_new);
		matrix_new[i] = matrix_old[i];
		// printf("matrix_new[%lu]: %p\n", i, matrix_new[i]);
		i++;
	}
	matrix_new[i] = row_new;
	matrix_new[n] = NULL;
	// printf("matrix_new:    %p\n", matrix_new);
	// printf("matrix_new[%lu]: %p\n", i, matrix_new[i]);
	// printf("matrix_new[%lu]: %p\n", n, matrix_new[n]);
	free(matrix_old);
	matrix_old = NULL;
	return (matrix_new);
}

static size_t	hf_len_array(size_t **matrix)
{
	size_t	m;

	m = 0;
	while (matrix[m])
		m++;
	return (m);
}

static char	**hf_free_matrix_char(char **matrix)
{
	size_t	i;

	i = 0;
	// printf("%p: -->%p<--\n", &matrix, matrix);
	while (matrix[i])
	{
		// printf("free(%p): -->%s<--\n", &matrix[i], matrix[i]);
		free(matrix[i]);
		matrix[i] = NULL; // not needed !!!
		// printf("free(%p): -->%s<--\n", &matrix[i], matrix[i]);
		i++;
	}
	// printf("free(%p): -->%s<--\n", &matrix, matrix);
	free(matrix);
	matrix = NULL;
	// printf("free(%p): -->%s<--\n", &matrix, matrix);
	return (matrix);
}

static size_t	**hf_free_matrix_size_t(size_t **matrix, size_t m)
{
	size_t	i;

	i = 0;
	// printf("%p: -->%p<--\n", &matrix, matrix);
	while (i > m)
	{
		// printf("free(%p): -->%lu<--\n", &matrix[i], matrix[i][0]);
		free(matrix[i]);
		matrix[i] = NULL;
		// printf("free(%p): -->%lu<--\n", &matrix[i], matrix[i][0]);
		i++;
	}
	// printf("free(%p): -->%s<--\n", &matrix, matrix[0]);
	free(matrix);
	matrix = NULL;
	// printf("free(%p): -->%s<--\n", &matrix, matrix[0]);
	return (matrix);
}

// int	main(void)
// {
// 	// char const	str[] = "xx1x123x12345x12xx ";
// 	// char		c = 'x';
// 	char const	str[] = "      split       this for   me  !       ";
// 	char		c = ' ';
// 	char		**strs;
// 	size_t		i;
// 	size_t		m;
// 	size_t		*row;
// 	size_t		**pos_len;

// 	printf("|-- start -->\n");
// 	// pos_len = hf_calc_substr(str,  c);
// 	// m = hf_len_array(pos_len);
// 	// printf("pos_len(%lu): %p --> %p\n", m, pos_len, *pos_len);
// 	// i = 0;
// 	// while (pos_len[i])
// 	// {
// 	// 	printf("%p: %lu --> %lu\n", pos_len[i], (pos_len[i])[0], (pos_len[i])[1]);
// 	// 	i++;
// 	// }
// 	printf("---\n");
// 	strs = ft_split(str, c);
// 	printf("%p: -->%p<--\n", &strs, strs);
// 	i = 0;
// 	while (strs[i])
// 	{
// 		printf("%p: -->%s<--\n", &strs[i], strs[i]);
// 		i++;
// 	}
// 	printf("%p: -->%s<--\n", &strs[i], strs[i]);
// 	// printf("%p: -->%p<--\n", &strs, strs);
// 	// strs = hf_free_matrix_char(strs);
// 	// printf("%p: -->%p<--\n", &strs, strs);
// 	printf("<-- end --|\n");
// 	return (0);
// }
