/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_enemy_moving_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/12 21:39:07 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_moving(t_game *game)
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
			if (((char *)game->map->value)[col] == 'M')
				init_enemy_moving_sub(game, row, col);
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
}

void	init_enemy_moving_sub(t_game *game, int row, int col)
{
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = rand_enemy_moving(row, col);
	node = llist_create(mlx_texture_to_image(game->mlx, texture));
	llist_add(&game->enemy_moving, node);
	mlx_image_to_window(game->mlx, game->enemy_moving->prev->value,
		col * TILE_SIZE + TILE_SIZE, row * -TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->enemy_moving->prev->value)->instances,
		LAYER_OTHERS);
	mlx_delete_texture(texture);
}

mlx_texture_t	*rand_enemy_moving(int row, int col)
{
	if ((rand() % (ft_max(col + row, 1))) % 2)
		return (mlx_load_png(PATH_ENEMY_ORANGE));
	else
		return (mlx_load_png(PATH_ENEMY_PURPLE));
}

void	move_enemy_moving(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy_moving;
	while (game->enemy_moving)
	{
		if (game->length_map_curr \
			&& ((mlx_image_t *)game->enemy_moving->value)->instances->y \
			>= ft_max(
				(game->length_map_orig - 4 + 1),
				MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
			((mlx_image_t *)game->enemy_moving->value)->instances->y = 0;
		else
			((mlx_image_t *)game->enemy_moving->value)->instances->y \
			+= TILE_SIZE;
		set_pos_x(game);
		llist_rot(&game->enemy_moving);
		if (tmp == game->enemy_moving)
			break ;
	}
}

void	free_enemy_moving(t_game *game)
{
	t_llist	*tmp;

	if (!game->enemy_moving)
		return ;
	game->enemy_moving->prev->next = NULL;
	while (game->enemy_moving)
	{
		tmp = game->enemy_moving;
		game->enemy_moving = (game->enemy_moving)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
