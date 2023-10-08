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


// --> from here
// solvability with flood fill

// solvability - 1EEEEE1
int	check_map_06(t_game *game)
{
	int		n;
	int		i_map;
	int		i_line;
	int		length_line;

	i_map = 0;
	length_line = ft_strlen((char *)game->map->value);
	while (i_map < game->length_map)
	{
		if (1 < i_map && i_map < game->length_map - 2)
		{
			n = 0;
			i_line = 1;
			while (i_line < length_line - 2)
			{
				if (((char *)game->map->value)[i_line] == 'E' \
					|| ((char *)game->map->value)[i_line] == 'M')
					n++;
				i_line++;
			}
			if (4 < n)
				return (0);
		}
		i_map++;
		llist_rot(&game->map);
	}
	return (1);
}

// solvability - free path
int	check_map_07(t_game *game)
{
	int	path;
	int		i_map;
	int		i_line;
	int		length_line;
	char	*line_next;

	i_map = 0;
	length_line = ft_strlen((char *)game->map->value);
	while (i_map < game->length_map)
	{
		if (1 < i_map && i_map < game->length_map - 2)
		{
			line_next = (char *)game->map->next->value;
			if (i_map == game->length_map - 3)
				line_next = (char *)game->map->next->next->next->next->next->value;
			path = 0;
			i_line = 1;
			ft_putstr(line_next);
			ft_putstr("\n");
			ft_putstr((char *)game->map->next->value);
			while (i_line < length_line - 2)
			{
				if ((((char *)game->map->value)[i_line] != 'E' \
					|| ((char *)game->map->value)[i_line] != 'M') \
					&& (line_next[i_line] != 'E' || line_next[i_line] != 'M'))
					path = 1;
				i_line++;
			}
			if (!path)
				return (0);
		}
		i_map++;
		llist_rot(&game->map);
	}
	return (1);
}


// solvability - E block C
int	check_map_08(t_game *game)
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
					if (!check_map_08_sub1(game, i_map, i_line) \
						&& !check_map_08_sub2(game, i_map, i_line))
						return (0);
				i_line++;
			}
		}
		i_map++;
		llist_rot(&game->map);
	}
	return (1);
}

// solvability  - E block C sub1
int	check_map_08_sub1(t_game *game, int i_map, int i_line)
{
	int		i;
	char	*line;
	char	*line_pre;

	i = i_line;
	line = (char *)game->map->value;
	line_pre = (char *)game->map->prev->value;
	if (i_map == 2)
		line_pre = (char *)game->map->prev->prev->prev->prev->prev->value;
	while (i < 6)
	{
		if (line[i] != 'E' && line[i] != 'M')
		{
			if (line_pre[i] != 'E' && line_pre[i] != 'M')
				return (1);
		}
		else
			return (0);
		i++;
	}	
	return (0);
}

// solvability  - E block C sub2
int	check_map_08_sub2(t_game *game, int i_map, int i_line)
{
	int		i;
	char	*line;
	char	*line_pre;

	i = i_line;
	line = (char *)game->map->value;
	line_pre = (char *)game->map->prev->value;
	if (i_map == 2)
		line_pre = (char *)game->map->prev->prev->prev->prev->prev->value;
	while (0 < i)
	{
		if (line[i] != 'E' && line[i] != 'M')
		{
			if (line_pre[i] != 'E' && line_pre[i] != 'M')
				return (1);
		}
		else
			return (0);
		i--;
	}	
	return (0);
}

// <-- to here