/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_dashboard_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:17:56 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/06 21:51:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_dashboard(t_game *game)
{
	char			*dashboard_str;
	mlx_texture_t	*texture;

	dashboard_str = ft_strdup(DASHBOARD_STR);
	texture = mlx_load_png(PATH_DASHBOARD);
	game->img_dashboard_bgr = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(
		game->mlx,
		game->img_dashboard_bgr,
		DASHBOARD_X,
		DASHBOARD_Y);
	mlx_set_instance_depth(game->img_dashboard_bgr->instances, LAYER_MSG);
	mlx_delete_texture(texture);
	str_img_dashboard_collectible_orig(game, &dashboard_str);
	game->img_dashboard_str = mlx_put_string(
			game->mlx,
			dashboard_str,
			DASHBOARD_X,
			DASHBOARD_Y);
	free(dashboard_str);
}

void	move_img_dashboard(t_game *game)
{
	char	*dashboard_str;

	dashboard_str = ft_strdup(DASHBOARD_STR);
	str_img_dashboard_speed(game, &dashboard_str);
	str_img_dashboard_collectible_curr(game, &dashboard_str);
	str_img_dashboard_collectible_orig(game, &dashboard_str);
	str_img_dashboard_time(game, &dashboard_str);
	mlx_delete_image(game->mlx, game->img_dashboard_str);
	game->img_dashboard_str = mlx_put_string(
			game->mlx,
			dashboard_str,
			DASHBOARD_X,
			DASHBOARD_Y);
	free(dashboard_str);
}

void	free_img_dashboard(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_dashboard_bgr);
	mlx_delete_image(game->mlx, game->img_dashboard_str);
}
