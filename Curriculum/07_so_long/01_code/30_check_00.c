/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_check_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:36:57 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 19:04:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	if (!check_map_sub1(game))
		return (0);
	if (!check_map_sub2(game))
		return (0);
	return (1);
}

int	check_map_sub1(t_game *game)
{
	if (!check_map_00(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_01(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_02(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_03(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	check_map_sub2(t_game *game)
{
	if (!check_map_04(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_05(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_06(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_07(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_map_08(game))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
