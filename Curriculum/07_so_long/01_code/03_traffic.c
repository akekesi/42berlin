/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_traffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/23 21:52:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_traffic(t_game *game)
{
	int				i;
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/car_blue_50x50.png");
	texture = mlx_load_png("assets/images/gasoline_50x50_small2.png");
	i = 5;
	while (i--)
	{
		node = llist_create(mlx_texture_to_image(game->mlx, texture));
		llist_add(&game->traffic, node);
		mlx_image_to_window(
			game->mlx,
			game->traffic->prev->value,
			i * 50 + 100,
			i * 50);
		mlx_set_instance_depth(
			((mlx_image_t *)game->traffic->prev->value)->instances,
			1);
	}
	mlx_delete_texture(texture);
}

void	move_traffic(t_game *game)
{
	int	i;

	i = 5;
	while (i--)
	{
		if (((mlx_image_t *)game->traffic->value)->instances->y == 450)
			((mlx_image_t *)game->traffic->value)->instances->y = 0;
		else
			((mlx_image_t *)game->traffic->value)->instances->y += 50;
		llist_rot(&game->traffic);
	}
}

void	free_traffic(t_game *game)
{
	t_llist	*tmp;

	game->traffic->prev->next = NULL;
	while (game->traffic)
	{
		tmp = game->traffic;
		game->traffic = (game->traffic)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
