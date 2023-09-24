/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 20:59:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	int				row;
	int				col;
	t_llist			*tmp;
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/car_blue_50x50.png");
	tmp = game->map;
	row = -1;
	while (1)
	{
		col = 1;
		while (((char *)game->map->value)[col] != '1')
		{
			if (((char *)game->map->value)[col] == 'E')
			{
				node = llist_create(mlx_texture_to_image(game->mlx, texture));
				llist_add(&game->enemy, node);
				mlx_image_to_window(
					game->mlx,
					game->enemy->prev->value,
					col * 50 + 50,
					row * -50);
				mlx_set_instance_depth(
					((mlx_image_t *)game->enemy->prev->value)->instances,
					1);
			}
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
	mlx_delete_texture(texture);
}

void	move_enemy(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy;
	while (1)
	{
		if (((mlx_image_t *)game->enemy->value)->instances->y == (game->length_map - 5) * TILE_SIZE)
			((mlx_image_t *)game->enemy->value)->instances->y = 0;
		else
			((mlx_image_t *)game->enemy->value)->instances->y += 50;
		llist_rot(&game->enemy);
		if (tmp == game->enemy)
			break ;
	}
}

void	free_enemy(t_game *game)
{
	t_llist	*tmp;

	game->enemy->prev->next = NULL;
	while (game->enemy)
	{
		tmp = game->enemy;
		game->enemy = (game->enemy)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
