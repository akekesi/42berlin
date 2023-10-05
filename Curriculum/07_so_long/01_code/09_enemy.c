/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 18:02:34 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	int				row;
	int				col;
	int				truck;
	t_llist			*tmp;
	t_llist			*node;
	mlx_texture_t	*texture;

	tmp = game->map;
	row = -1;
	while (game->map)
	{
		col = 1;
		while (((char *)game->map->value)[col] != '1')
		{
			if (((char *)game->map->value)[col] == 'E')
			{
				if (((char *)game->map->next->value)[col] == 'E' && !truck)
				{
					texture = rand_enemy(2, row, col);
					truck = 1;
				}
				else if (((char *)game->map->prev->value)[col] == 'E' && truck)
				{
					texture = rand_enemy(1, row, col);
					truck = 0;
				}
				else
					texture = rand_enemy(0, row, col);
				node = llist_create(mlx_texture_to_image(game->mlx, texture));
				llist_add(&game->enemy, node);
				mlx_image_to_window(game->mlx, game->enemy->prev->value, col * TILE_SIZE + TILE_SIZE, row * -TILE_SIZE);
				mlx_set_instance_depth(((mlx_image_t *)game->enemy->prev->value)->instances, 1);
				mlx_delete_texture(texture);
			}
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
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
		if (game->length_collectible_curr && ((mlx_image_t *)game->enemy->value)->instances->y == ft_max((game->length_map - 5), MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
			((mlx_image_t *)game->enemy->value)->instances->y = 0;
		else
			((mlx_image_t *)game->enemy->value)->instances->y += TILE_SIZE;
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}

void	find_enemy_front(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (game->enemy)
	{
		if (
			((mlx_image_t *)game->enemy->value)->instances->x == game->img_player->instances->x
			&& ((mlx_image_t *)game->enemy->value)->instances->y + TILE_SIZE == game->img_player->instances->y)
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
			((mlx_image_t *)game->enemy->value)->instances->x == game->img_player->instances->x - TILE_SIZE
			&& ((mlx_image_t *)game->enemy->value)->instances->y == game->img_player->instances->y)
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
			((mlx_image_t *)game->enemy->value)->instances->x == game->img_player->instances->x + TILE_SIZE
			&& ((mlx_image_t *)game->enemy->value)->instances->y == game->img_player->instances->y)
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
