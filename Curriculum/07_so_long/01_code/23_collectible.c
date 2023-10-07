/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:45:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/07 18:10:40 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_collectible(t_game *game)
{
	int				row;
	int				col;
	t_llist			*tmp;

	row = -1;
	tmp = game->map;
	while (game->map)
	{
		col = 1;
		while (((char *)game->map->value)[col] != '1')
		{
			if (((char *)game->map->value)[col] == 'C')
				init_collectible_sub(game, row, col);
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
}

void	init_collectible_sub(t_game *game, int row, int col)
{
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_COLLECTIBLE);
	node = llist_create(mlx_texture_to_image(game->mlx, texture));
	llist_add(&game->collectible, node);
	mlx_image_to_window(
		game->mlx,
		game->collectible->prev->value,
		col * TILE_SIZE + TILE_SIZE,
		row * -TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->collectible->prev->value)->instances,
		LAYER_OTHERS);
	game->length_collectible_curr++;
	game->length_collectible_orig++;
	mlx_delete_texture(texture);
}

void	move_collectible(t_game *game)
{
	t_llist	*tmp;

	tmp = game->collectible;
	while (game->collectible)
	{
		if (((mlx_image_t *)game->collectible->value)->instances->y \
			== ft_max(
				(game->length_map - 5), MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
			((mlx_image_t *)game->collectible->value)->instances->y = 0;
		else
			((mlx_image_t *)game->collectible->value)->instances->y \
			+= TILE_SIZE;
		llist_rot(&game->collectible);
		if (tmp == game->collectible)
			break ;
	}
}

void	find_collectible(t_game *game)
{
	t_llist	*tmp;

	tmp = game->collectible;
	while (game->collectible)
	{
		if (((mlx_image_t *)game->collectible->value)->instances->x \
			== game->img_player->instances->x
			&& ((mlx_image_t *)game->collectible->value)->instances->y \
			== game->img_player->instances->y \
			&& ((mlx_image_t *)game->collectible->value)->instances->enabled \
			== true)
		{
			((mlx_image_t *)game->collectible->value)->instances->enabled \
			= false;
			game->length_collectible_curr--;
		}
		llist_rot(&game->collectible);
		if (tmp == game->collectible)
			break ;
	}
}

void	free_collectible(t_game *game)
{
	t_llist	*tmp;

	if (!game->collectible)
		return ;
	game->collectible->prev->next = NULL;
	while (game->collectible)
	{
		tmp = game->collectible;
		game->collectible = (game->collectible)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
