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
	if (c == 'M')
		return (1);
	if (c == 'C')
		return (1);
	return (0);
}
