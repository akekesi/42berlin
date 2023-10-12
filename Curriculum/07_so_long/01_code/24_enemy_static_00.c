/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_enemy_static_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/12 21:39:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_static(t_game *game)
{
	int				row;
	int				col;
	int				truck;
	t_llist			*tmp;

	row = -1;
	truck = 0;
	tmp = game->map;
	while (game->map)
	{
		col = 1;
		while (((char *)game->map->value)[col] != '1')
		{
			if (((char *)game->map->value)[col] == 'E')
				init_enemy_static_sub(game, row, col, &truck);
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
}

void	init_enemy_static_sub(t_game *game, int row, int col, int *truck)
{
	t_llist			*node;
	mlx_texture_t	*texture;

	if (((char *)game->map->next->value)[col] == 'E' && !(*truck))
	{
		texture = rand_enemy_static(2, row, col);
		*truck = 1;
	}
	else if (((char *)game->map->prev->value)[col] == 'E' && *truck)
	{
		texture = rand_enemy_static(1, row, col);
		*truck = 0;
	}
	else
		texture = rand_enemy_static(0, row, col);
	node = llist_create(mlx_texture_to_image(game->mlx, texture));
	llist_add(&game->enemy_static, node);
	mlx_image_to_window(game->mlx, game->enemy_static->prev->value,
		col * TILE_SIZE + TILE_SIZE, row * -TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->enemy_static->prev->value)->instances,
		LAYER_OTHERS);
	mlx_delete_texture(texture);
}

mlx_texture_t	*rand_enemy_static(int truck, int row, int col)
{
	if (truck == 1)
		return (mlx_load_png(PATH_ENEMY_TRUCK_FRONT));
	if (truck == 2)
		return (mlx_load_png(PATH_ENEMY_TRUCK_REAR));
	if ((rand() % (ft_max(col + row, 1))) % 2)
		return (mlx_load_png(PATH_ENEMY_BLUE));
	else
		return (mlx_load_png(PATH_ENEMY_YELLOW));
}

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
