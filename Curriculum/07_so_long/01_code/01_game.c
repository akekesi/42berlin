/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/28 18:39:51 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		ft_putstr("Error");
	game->map = read_map(fd);
	game->length_map = llist_len(game->map);
	if (check_map_00(game))
		ft_putstr("OK-00\n");
	if (check_map_01(game))
		ft_putstr("OK-01\n");
	if (check_map_02(game))
		ft_putstr("OK-02\n");
	if (check_map_03(game))
		ft_putstr("OK-03\n");
	if (check_map_04(game))
		ft_putstr("OK-04\n");
	if (check_map_05(game))
		ft_putstr("OK-05\n");
	if (check_map_06(game))
		ft_putstr("OK-06\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "Road Fighter", false);
	game->player = NULL;
	game->win = NULL;
	game->road = NULL;
	game->enemy = NULL;
	game->collectible = NULL;
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_delta = 1000 / game->speed;
}

void	loop_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

void	move_game(t_game *game)
{
	if (game->time_delta <= get_time_elapsed(game->time_last))
	{
		move_road(game);
		move_enemy(game);
		move_collectible(game);
		game->time_last = get_time_current();
	}
	find_enemy(game);
	find_collectible(game);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			game->speed = ft_min(game->speed + 1, 10);
			game->time_delta = 1000 / game->speed;
		}
		if (keydata.key == MLX_KEY_DOWN)
		{
			game->speed = ft_max(game->speed - 1, 1);
			game->time_delta = 1000 / game->speed;
		}
		if (keydata.key == MLX_KEY_LEFT)
			game->player->instances->x = ft_max(game->player->instances->x - TILE_SIZE, 2 * TILE_SIZE);
		if (keydata.key == MLX_KEY_RIGHT)
			game->player->instances->x = ft_min(game->player->instances->x + TILE_SIZE, MAP_WIDTH - 3 * TILE_SIZE);
	}
}

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
	move_game(game);
}
