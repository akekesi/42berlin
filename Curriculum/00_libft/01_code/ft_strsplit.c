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

#include "libft.h"
#include <stdio.h>

char			**ft_strsplit(char const *str, char c);
static size_t	hf_calc_substr(char const *str, char c);
static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n);

char	**ft_strsplit(char const *str, char c)
{
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
			printf("%lu. %lu --> %lu\n", n, i - prev, prev);
			prev = 0;
		}
		if (str[i] != c)
			prev++;
		i++;
	}
	if (prev)
	{
		n++;
		printf("%lu. %lu --> %lu\n", n, i - prev, prev);
	}
	return (n);
}

static size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n)
{
	size_t	i;
	size_t	**matrix_new;

	matrix_new = (size_t **)malloc(sizeof(size_t *) * (n + 1));
	if (!matrix_new)
		return (NULL);
	i = 0;
	printf("matrix_old:    %p\n", matrix_old);
	printf("matrix_old[%lu]: %p\n", i, matrix_old[i]);
	while (i < n && matrix_old[i])
	{
		printf("matrix_new:    %p\n", matrix_new);
		matrix_new[i] = matrix_old[i];
		printf("matrix_new[%lu]: %p\n", i, matrix_new[i]);
		i++;
	}
	matrix_new[i] = row_new;
	matrix_new[n] = NULL;
	printf("matrix_new:    %p\n", matrix_new);
	printf("matrix_new[%lu]: %p\n", i, matrix_new[i]);
	printf("matrix_new[%lu]: %p\n", n, matrix_new[n]);
	// free(matrix_old);
	return (matrix_new);
}

int	main(void)
{
	char const	str[] = "xx1x123x12345x12xx ";
	char		c = 'x';
	size_t		i;
	size_t		n;
	size_t		*row;
	size_t		**pos_len;

	n = hf_calc_substr(str,  c);
	printf("n: %lu\n", n);

	pos_len = (size_t **)malloc(sizeof(size_t *) * 1);
	pos_len[0] = NULL;

	printf("---\n");
	row = (size_t *)malloc(sizeof(size_t) * 2);
	row[0] = 2;
	row[1] = 1;
	printf("matrix_new:    %p\n", pos_len);
	printf("matrix_new[%lu]: %p\n", 0, pos_len[0]);
	printf("row:           %p\n", row);
	pos_len = hf_add_row(pos_len, row, 1);
	printf("matrix_new:    %p\n", pos_len);
	i = 0;
	while (pos_len[i])
	{
		printf("%p: %lu --> %lu\n", pos_len[i], (pos_len[i])[0], (pos_len[i])[1]);
		i++;
	}

	printf("---\n");
	row = (size_t *)malloc(sizeof(size_t) * 2);
	row[0] = 4;
	row[1] = 3;
	printf("matrix_new:    %p\n", pos_len);
	printf("matrix_new[%lu]: %p\n", 0, pos_len[0]);
	printf("row:           %p\n", row);
	pos_len = hf_add_row(pos_len, row, 2);
	printf("matrix_new:    %p\n", pos_len);
	i = 0;
	while (pos_len[i])
	{
		printf("%p: %lu --> %lu\n", pos_len[i], (pos_len[i])[0], (pos_len[i])[1]);
		i++;
	}
	return (0);
}
