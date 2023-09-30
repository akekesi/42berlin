/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/30 23:54:44 by akekesi          ###   ########.fr       */
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
	game->img_player = NULL;
	game->img_price = NULL;
	game->img_start = NULL;
	game->img_stop = NULL;
	game->img_win = NULL;
	game->img_lose = NULL;
	game->road = NULL;
	game->enemy = NULL;
	game->collectible = NULL;
	game->start_stop = 0;
	game->won = 0;
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_delta = 1000 / game->speed;
	game->length_collectible = 0;
}

void	loop_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

void	move_game(t_game *game)
{
	if (game->img_player->instances->y < 0)
	{
		game->start_stop = 0;
	}
	if (game->start_stop)
	{
		game->img_start->instances->y = -TILE_SIZE;
		game->img_stop->instances->y = -TILE_SIZE;
		if (game->time_delta <= get_time_elapsed(game->time_last))
		{
			move_road(game);
			move_enemy(game);
			move_collectible(game);
			game->time_last = get_time_current();
			if (!game->length_collectible)
				move_img_price(game);
			if (game->won)
			{
				move_img_player(game);
				game->img_win->instances->y = 2 * TILE_SIZE;
			}
		}
		// mlx_put_string(game->mlx, "speed: xxx km/h", 0, 400);
		// mlx_put_string(game->mlx, "time:  xxx sec", 0, 420);
		// mlx_put_string(game->mlx, "tanks: x/y", 0, 440);
		// mlx_put_string(game->mlx, "price: x/y", 0, 460);
		find_enemy(game);
		find_collectible(game);
		find_img_price(game);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_SPACE && game->img_win->instances->y < 0 && game->img_lose->instances->y < 0)
		{
			game->start_stop = (game->start_stop + 1) % 2;
			if (!game->start_stop)
				game->img_stop->instances->y = 2 * TILE_SIZE;
		}
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (game->start_stop)
		{
			if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			{
				game->speed = ft_min(game->speed + 1, 10);
				game->time_delta = 1000 / game->speed;
			}
			if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			{
				game->speed = ft_max(game->speed - 1, 1);
				game->time_delta = 1000 / game->speed;
			}
			if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
				game->img_player->instances->x = ft_max(game->img_player->instances->x - TILE_SIZE, 2 * TILE_SIZE);
			if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
				game->img_player->instances->x = ft_min(game->img_player->instances->x + TILE_SIZE, MAP_WIDTH - 3 * TILE_SIZE);
		}
	}
}

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
	move_game(game);
}
