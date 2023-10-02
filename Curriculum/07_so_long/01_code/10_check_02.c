/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_check_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:59:03 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/02 21:59:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// validity
int	check_map_05(t_game *game)
{
	int		i_map;
	int		i_line;
	int		length_line;

	i_map = 0;
	length_line = ft_strlen((char *)game->map->value);
	while (i_map < game->length_map)
	{
		if (1 < i_map && i_map < game->length_map - 2)
		{
			i_line = 1;
			while (i_line < length_line - 2)
			{
				if (!check_map_05_sub(((char *)game->map->value)[i_line]))
					return (0);
				i_line++;
			}
		}
		i_map++;
		llist_rot(&game->map);
	}
	return (1);
}

// validity sub
int	check_map_05_sub(char c)
{
	if (c == '0')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'C')
		return (1);
	return (0);
}

// solvability
int	check_map_06(t_game *game)
{
	int		i_map;
	int		i_line;
	int		length_line;

	i_map = 0;
	length_line = ft_strlen((char *)game->map->value);
	while (i_map < game->length_map)
	{
		if (1 < i_map && i_map < game->length_map - 2)
		{
			i_line = 1;
			while (i_line < length_line - 2)
			{
				if (((char *)game->map->value)[i_line] == 'C')
					if (!check_map_06_sub1(game, i_map, i_line))
						return (0);
				i_line++;
			}
		}
		i_map++;
		llist_rot(&game->map);
	}
	return (1);
}

// solvability sub1
int	check_map_06_sub1(t_game *game, int i_map, int i_line)
{
	char	*line_pre;
	char	*line_next;

	line_pre = (char *)game->map->prev->value;
	line_next = (char *)game->map->next->value;
	if (i_map == 2)
		line_pre = (char *)game->map->prev->prev->prev->prev->prev->value;
	if (i_map == game->length_map - 3)
		line_next = (char *)game->map->next->next->next->next->next->value;
	if (!check_map_06_sub2(line_pre, i_line))
		return (0);
	if (!check_map_06_sub2(line_next, i_line))
		return (0);
	return (1);
}

// solvability sub2
int	check_map_06_sub2(char *line, int i_line)
{
	int	length_line;

	length_line = ft_strlen(line);
	if (line[i_line] != 'E')
		return (1);
	if (1 < i_line)
		if (line[i_line - 1] != 'E')
			return (1);
	if (2 < i_line)
		if (line[i_line - 2] != 'E')
			return (1);
	if (i_line < length_line - 2)
		if (line[i_line + 1] != 'E')
			return (1);
	if (i_line < length_line - 3)
		if (line[i_line + 2] != 'E')
			return (1);
	return (0);
}
