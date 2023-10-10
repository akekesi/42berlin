/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_check_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:04:16 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 02:04:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// solvability - from P to C
int	check_map_06(t_game *game)
{
	int		result;
	t_point	size;
	t_point	start;
	char	**map_matrix;

	map_matrix = get_map_matrix(game);
	if (!map_matrix)
		return (0);
	size.x = ft_strlen(map_matrix[0]);
	size.y = game->length_map - 2;
	start.x = 1;
	start.y = 1;
	flood_fill(map_matrix, size, start, 'U');
	result = check_map_06_sub(map_matrix, size);
	free_map_matrix(map_matrix, size);
	return (result);
}

int	check_map_06_sub(char **map_matrix, t_point size)
{
	int		row_i;
	int		col_i;

	row_i = 0;
	while (row_i < size.y)
	{
		col_i = 0;
		while (col_i < size.x)
		{
			if (map_matrix[row_i][col_i] == 'C')
				return (0);
			col_i++;
		}
		row_i++;
	}
	return (1);
}

// solvability - from C to W
int	check_map_07(t_game *game)
{
	int		result;
	t_point	size;
	char	**map_matrix;

	map_matrix = get_map_matrix(game);
	if (!map_matrix)
		return (0);
	size.x = ft_strlen(map_matrix[0]);
	size.y = game->length_map - 2;
	result = check_map_07_sub1(game, map_matrix, size);
	free_map_matrix(map_matrix, size);
	return (result);
}

int	check_map_07_sub1(t_game *game, char **map_matrix, t_point size)
{
	int		row_i;
	int		col_i;

	row_i = 0;
	while (row_i < size.y)
	{
		col_i = 0;
		while (col_i < size.x)
		{
			if (map_matrix[row_i][col_i] == 'C')
			{
				if (!check_map_07_sub2(game, row_i, col_i))
					return (0);
			}
			col_i++;
		}
		row_i++;
	}
	return (1);
}

int	check_map_07_sub2(t_game *game, int row, int col)
{
	t_point	size;
	t_point	start;
	char	c;
	char	**map_matrix;

	map_matrix = get_map_matrix(game);
	if (!map_matrix)
		return (0);
	size.x = ft_strlen(map_matrix[0]);
	size.y = game->length_map - 2;
	start.x = col;
	start.y = row;
	flood_fill(map_matrix, size, start, 'U');
	c = map_matrix[size.y - 1][1];
	free_map_matrix(map_matrix, size);
	if (c != 'F')
		return (0);
	return (1);
}
