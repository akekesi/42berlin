/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_police.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 20:36:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_police(t_game *game)
{
	init_police_sub(game, PATH_POLICE_BLUE);
	init_police_sub(game, PATH_POLICE_RED);
}

void	init_police_sub(t_game *game, char *path_png)
{
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path_png);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	node = llist_create(mlx_texture_to_image(game->mlx, texture));
	llist_add(&game->police, node);
	mlx_image_to_window(game->mlx, game->police->prev->value,
		6 * TILE_SIZE, MAP_HEIGHT + TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->police->prev->value)->instances, LAYER_OTHERS);
	((mlx_image_t *)game->police->prev->value)->instances->enabled = false;
	mlx_delete_texture(texture);
}

void	move_police(t_game *game)
{
	t_llist	*tmp;

	tmp = game->police;
	while (game->police)
	{
		if (((mlx_image_t *)game->police->value)->instances->x \
			> game->img_player->instances->x)
			((mlx_image_t *)game->police->value)->instances->x -= TILE_SIZE / 2;
		if (((mlx_image_t *)game->police->value)->instances->x \
			< game->img_player->instances->x)
			((mlx_image_t *)game->police->value)->instances->x += TILE_SIZE / 2;
		((mlx_image_t *)game->police->value)->instances->y -= TILE_SIZE;
		((mlx_image_t *)game->police->prev->value)->instances->enabled = false;
		llist_rot(&game->police);
		if (tmp == game->police)
			break ;
	}
	llist_rot(&game->police);
	((mlx_image_t *)game->police->value)->instances->enabled = true;
}

void	free_police(t_game *game)
{
	t_llist	*tmp;

	if (!game->police)
		return ;
	game->police->prev->next = NULL;
	while (game->police)
	{
		tmp = game->police;
		game->police = (game->police)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
