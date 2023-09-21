/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx42_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:38:48 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/21 20:35:15 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
			game->car->instances->y -= 50;
		if (keydata.key == MLX_KEY_DOWN)
			game->car->instances->y += 50;
		if (keydata.key == MLX_KEY_LEFT)
			game->car->instances->x -= 50;
		if (keydata.key == MLX_KEY_RIGHT)
			game->car->instances->x += 50;
	}
}

static void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
}

int32_t	test_mlx42_00(void)
{
	t_game			game;
	mlx_texture_t	*texture;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "test", false);
	if (!game.mlx)
		ft_error();
	
	texture = mlx_load_png("assets/images/enemy.png");
	if (!texture)
		ft_error();
	game.car = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	if (!game.car)
		ft_error();
	if (mlx_image_to_window(game.mlx, game.car, 190, 130) < 0)
		ft_error();
	
	texture = mlx_load_png("assets/images/road_line_01.png");
	if (!texture)
		ft_error();
	game.road1 = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	if (!game.road1)
		ft_error();
	if (mlx_image_to_window(game.mlx, game.road1, 0, 0) < 0)
		ft_error();

	texture = mlx_load_png("assets/images/road_line_02.png");
	if (!texture)
		ft_error();
	game.road2 = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	if (!game.road2)
		ft_error();
	if (mlx_image_to_window(game.mlx, game.road2, 0, 50) < 0)
		ft_error();

	mlx_loop_hook(game.mlx, &ft_hook, &game.mlx);
	mlx_key_hook(game.mlx, &key_hook, &game.mlx);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.car);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
