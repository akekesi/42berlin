/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_enemy_static_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 21:32:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_static(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy_static;
	while (game->enemy_static)
	{
		if (game->length_map_curr \
			&& ((mlx_image_t *)game->enemy_static->value)->instances->y \
			>= ft_max(
				(game->length_map_orig - 4 + 1),
				MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
			((mlx_image_t *)game->enemy_static->value)->instances->y = 0;
		else
			((mlx_image_t *)game->enemy_static->value)->instances->y \
			+= TILE_SIZE;
		llist_rot(&game->enemy_static);
		if (tmp == game->enemy_static)
			break ;
	}
}

void	free_enemy_static(t_game *game)
{
	t_llist	*tmp;

	if (!game->enemy_static)
		return ;
	game->enemy_static->prev->next = NULL;
	while (game->enemy_static)
	{
		tmp = game->enemy_static;
		game->enemy_static = (game->enemy_static)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
