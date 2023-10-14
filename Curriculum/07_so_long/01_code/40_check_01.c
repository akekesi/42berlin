/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40_check_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:36:57 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/14 20:10:41 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// lengths of map and lines
int	check_map_00(t_game *game)
{
	int	i;
	int	length;

	if (!game->map)
		return (0);
	length = ft_strlen((char *)game->map->value);
	if (game->length_map_orig < 4 || length < 7)
		return (0);
	i = 0;
	while (i < game->length_map_orig)
	{
		if (ft_strlen(game->map->value) != length)
			return (0);
		llist_rot(&game->map);
		i++;
	}
	return (1);
}

// first and last characters of lines
int	check_map_01(t_game *game)
{
	int	i;
	int	length;

	length = ft_strlen((char *)game->map->value);
	i = 0;
	while (i < game->length_map_orig)
	{
		if (((char *)game->map->value)[0] != '1')
			return (0);
		if (((char *)game->map->value)[length - 2] != '1')
			return (0);
		llist_rot(&game->map);
		i++;
	}
	return (1);
}

// first and last lines
int	check_map_02(t_game *game)
{
	int	i;
	int	length;

	length = ft_strlen((char *)game->map->value);
	i = 0;
	while (i < length - 1)
	{
		if (((char *)game->map->value)[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (((char *)game->map->prev->value)[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// player
int	check_map_03(t_game *game)
{
	int	i;
	int	length;
	int	flag;

	length = ft_strlen((char *)game->map->value);
	if (((char *)game->map->next->value)[0] != '1')
		return (0);
	if (((char *)game->map->next->value)[length - 2] != '1')
		return (0);
	i = 1;
	flag = 0;
	while (i < length - 2)
	{
		if (((char *)game->map->next->value)[i] == 'P')
			flag++;
		else if (((char *)game->map->next->value)[i] != '0')
			return (0);
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

// win
int	check_map_04(t_game *game)
{
	int	i;
	int	length;
	int	flag;

	length = ft_strlen((char *)game->map->value);
	if (((char *)game->map->prev->prev->value)[0] != '1')
		return (0);
	if (((char *)game->map->prev->prev->value)[length - 2] != '1')
		return (0);
	i = 1;
	flag = 0;
	while (i < length - 2)
	{
		if (((char *)game->map->prev->prev->value)[i] == 'W')
			flag++;
		else if (((char *)game->map->prev->prev->value)[i] != '0')
			return (0);
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}
