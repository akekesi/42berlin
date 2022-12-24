/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:17:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/24 19:36:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			**ft_split(char const *str, char c);
static size_t	**hf_calc_pos_len(char const *str, char c);
static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n);
static size_t	hf_len_array(size_t **matrix);
static char		**hf_free_matrix_char(char **matrix);
static size_t	**hf_free_matrix_size_t(size_t **matrix);

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	m;
	size_t	**pos_len;
	char	**strs;

	if (!str)
		return (NULL);
	pos_len = hf_calc_pos_len(str, c);
	if (!pos_len)
		return (NULL);
	m = hf_len_array(pos_len);
	strs = (char **)malloc(sizeof(char *) * (m + 1));
	if (!strs)
	{
		pos_len = hf_free_matrix_size_t(pos_len);
		return (NULL);
	}
	i = 0;
	while (i < m)
	{
		strs[i] = (char *)malloc(sizeof(char) * (pos_len[i][1] + 1));
		if (!strs[i])
		{
			strs = hf_free_matrix_char(strs);
			pos_len = hf_free_matrix_size_t(pos_len);
			return (NULL);
		}
		strs[i] = ft_memcpy(strs[i], str + pos_len[i][0], pos_len[i][1]);
		strs[i][pos_len[i][1]] = '\0';
		i++;
	}
	strs[m] = NULL;
	pos_len = hf_free_matrix_size_t(pos_len);
	return (strs);
}

static size_t	**hf_calc_pos_len(char const *str, char c)
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
	if (!pos_len)
		return (NULL);
	pos_len[0] = NULL;
	while (str[i])
	{
		if (str[i] == c && prev)
		{
			n++;
			row = (size_t *)malloc(sizeof(size_t) * 2);
			if (!row)
			{
				pos_len = hf_free_matrix_size_t(pos_len);
				return (NULL);
			}
			row[0] = i - prev;
			row[1] = prev;
			pos_len = hf_add_row(pos_len, row, n);
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
		{
			pos_len = hf_free_matrix_size_t(pos_len);
			return (NULL);
		}
		row[0] = i - prev;
		row[1] = prev;
		pos_len = hf_add_row(pos_len, row, n);
	}
	return (pos_len);
}

static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n)
{
	size_t	i;
	size_t	**matrix_new;

	matrix_new = (size_t **)malloc(sizeof(size_t *) * (n + 1));
	if (!matrix_new)
	// {
	// 	matrix_old = hf_free_matrix_char(matrix_old);
		return (NULL);
	// }
	i = 0;
	while (i < n && matrix_old[i])
	{
		matrix_new[i] = matrix_old[i];
		i++;
	}
	matrix_new[i] = row_new;
	matrix_new[n] = NULL;
	free(matrix_old);
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
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (matrix);
}

static size_t	**hf_free_matrix_size_t(size_t **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
