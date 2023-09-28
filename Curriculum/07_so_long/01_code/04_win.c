/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/28 20:47:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_game *game)
{
	int				i;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/win.png");
	game->win = mlx_texture_to_image(game->mlx, texture);
	i = 1;
	while (i)
	{
		if (((char *)game->map->prev->prev->value)[i] == 'W')
		{
			mlx_image_to_window(game->mlx, game->win, (i + 1) * TILE_SIZE, -TILE_SIZE);
			break ;
		}
		i++;
	}
	mlx_set_instance_depth(game->win->instances, 2);
	mlx_delete_texture(texture);
}

void	move_win(t_game *game)
{
	if (game->win->instances->y == (game->length_map - 5) * TILE_SIZE)
			game->win->instances->y = 0;
		else
			game->win->instances->y += 50;
}

void	find_win(t_game *game)
{
	if (game->win->instances->x == game->player->instances->x
		&& game->win->instances->y == game->player->instances->y)
			game->win->instances->y -= 9999;
}

void	free_win(t_game *game)
{
	mlx_delete_image(game->mlx, game->win);
}
