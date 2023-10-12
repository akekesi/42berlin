/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_map_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:20:36 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/12 18:15:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map_matrix(t_game *game)
{
	t_point	size;
	char	**map_matrix;

	size.x = ft_strlen(game->map->value);
	size.y = game->length_map_orig - 2;
	map_matrix = (char **)malloc(sizeof(char *) * size.y);
	if (!map_matrix)
		return (NULL);
	llist_rot(&game->map);
	get_map_matrix_sub(game, map_matrix, size);
	llist_rot(&game->map);
	return (map_matrix);
}

void	get_map_matrix_sub(t_game *game, char **map_matrix, t_point size)
{
	int		row_i;
	int		col_i;

	row_i = 0;
	while (row_i < size.y)
	{
		col_i = 0;
		map_matrix[row_i] = (char *)malloc(sizeof(char) * (size.x + 1));
		if (!map_matrix[row_i])
		{
			free_map_matrix(map_matrix, size);
			map_matrix = NULL;
			return ;
		}
		while (col_i < size.x)
		{
			map_matrix[row_i][col_i] = ((char *)game->map->value)[col_i];
			col_i++;
		}
		map_matrix[row_i][col_i] = '\0';
		row_i++;
		llist_rot(&game->map);
	}
}

void	print_map_matrix(char **map_matrix, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		ft_putstr(map_matrix[i]);
		i++;
	}
}

void	free_map_matrix(char **map_matrix, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		free(map_matrix[i]);
		i++;
	}
	free(map_matrix);
}
