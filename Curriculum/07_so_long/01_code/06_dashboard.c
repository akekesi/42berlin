/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_dashboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:17:56 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 19:51:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_dashboard(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/dashboard_bgr.png");
	game->img_dashboard_bgr = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_dashboard_bgr, DASHBOARD_X, DASHBOARD_Y);
	mlx_set_instance_depth(game->img_dashboard_bgr->instances, 2);
	mlx_delete_texture(texture);
}

void	move_img_dashboard(t_game *game)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;
	char	speed[] = "speed:    km/h | ";
	char	score[] = "score:   /   | ";
	char	time[] =  "time:  1234.5s";

	str = ft_itoa(game->speed * 20);
	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		speed[9 - i] = str[j - i - 1];
		i++;
	}
	free(str);
	if (game->length_collectible_orig < 100)
	{
		str = ft_itoa(game->length_collectible_orig);
		i = 0;
		j = ft_strlen(str);
		while (i < j)
		{
			score[11 - i] = str[j - i - 1];
			i++;
		}
		free(str);
		str = ft_itoa(game->length_collectible_orig - game->length_collectible_curr);
		i = 0;
		j = ft_strlen(str);
		while (i < j)
		{
			score[8 - i] = str[j - i - 1];
			i++;
		}
		free(str);
	}
	tmp = ft_strjoin(speed, score);
	str = ft_strjoin(tmp, time);
	mlx_delete_image(game->mlx, game->img_dashboard_fgr);
	game->img_dashboard_fgr = mlx_put_string(game->mlx, str, DASHBOARD_X, DASHBOARD_Y);
	free(tmp);
	free(str);
}

void	free_img_dashboard(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_dashboard_bgr);
	mlx_delete_image(game->mlx, game->img_dashboard_fgr);
}
