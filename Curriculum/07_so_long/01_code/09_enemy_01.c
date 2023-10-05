/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_enemy_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 20:35:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy_front(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (game->enemy)
	{
		if (
			((mlx_image_t *)game->enemy->value)->instances->x \
			== game->img_player->instances->x
			&& ((mlx_image_t *)game->enemy->value)->instances->y + TILE_SIZE \
			== game->img_player->instances->y)
		{
			game->start_stop = 0;
			game->img_lose->instances->y = MSG_Y;
			game->img_crash->instances->x = game->img_player->instances->x;
			game->img_crash->instances->y = game->img_player->instances->y - 25;
			return ;
		}
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}

void	find_enemy_left(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (game->enemy)
	{
		if (
			((mlx_image_t *)game->enemy->value)->instances->x \
			== game->img_player->instances->x - TILE_SIZE
			&& ((mlx_image_t *)game->enemy->value)->instances->y \
			== game->img_player->instances->y)
		{
			game->start_stop = 0;
			game->img_lose->instances->y = MSG_Y;
			game->img_crash->instances->x = game->img_player->instances->x - 35;
			game->img_crash->instances->y = game->img_player->instances->y;
			return ;
		}
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}

void	find_enemy_right(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (game->enemy)
	{
		if (
			((mlx_image_t *)game->enemy->value)->instances->x \
			== game->img_player->instances->x + TILE_SIZE
			&& ((mlx_image_t *)game->enemy->value)->instances->y \
			== game->img_player->instances->y)
		{
			game->start_stop = 0;
			game->img_lose->instances->y = MSG_Y;
			game->img_crash->instances->x = game->img_player->instances->x + 35;
			game->img_crash->instances->y = game->img_player->instances->y;
			return ;
		}
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}
