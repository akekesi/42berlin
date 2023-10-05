/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_enemy_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 20:54:20 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
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
				init_enemy_sub(game, row, col, &truck);
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
}

void	init_enemy_sub(t_game *game, int row, int col, int *truck)
{
	t_llist			*node;
	mlx_texture_t	*texture;

	if (((char *)game->map->next->value)[col] == 'E' && !(*truck))
	{
		texture = rand_enemy(2, row, col);
		*truck = 1;
	}
	else if (((char *)game->map->prev->value)[col] == 'E' && *truck)
	{
		texture = rand_enemy(1, row, col);
		*truck = 0;
	}
	else
		texture = rand_enemy(0, row, col);
	node = llist_create(mlx_texture_to_image(game->mlx, texture));
	llist_add(&game->enemy, node);
	mlx_image_to_window(
		game->mlx,
		game->enemy->prev->value,
		col * TILE_SIZE + TILE_SIZE,
		row * -TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->enemy->prev->value)->instances, 1);
	mlx_delete_texture(texture);
}

mlx_texture_t	*rand_enemy(int truck, int row, int col)
{
	if (truck == 1)
		return (mlx_load_png(PATH_ENEMY_TRUCK_FRONT));
	if (truck == 2)
		return (mlx_load_png(PATH_ENEMY_TRUCK_REAR));
	if ((rand() % (col + row)) % 2)
		return (mlx_load_png(PATH_ENEMY_BLUE));
	else
		return (mlx_load_png(PATH_ENEMY_YELLOW));
}

void	move_enemy(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (game->enemy)
	{
		if (game->length_collectible_curr \
			&& ((mlx_image_t *)game->enemy->value)->instances->y \
			== ft_max(
				(game->length_map - 5),
				MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
			((mlx_image_t *)game->enemy->value)->instances->y = 0;
		else
			((mlx_image_t *)game->enemy->value)->instances->y += TILE_SIZE;
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}

void	free_enemy(t_game *game)
{
	t_llist	*tmp;

	if (!game->enemy)
		return ;
	game->enemy->prev->next = NULL;
	while (game->enemy)
	{
		tmp = game->enemy;
		game->enemy = (game->enemy)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}