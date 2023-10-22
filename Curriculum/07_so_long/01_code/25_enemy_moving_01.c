/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_enemy_moving_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/22 17:19:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos_x(t_game *game)
{
	t_llist	*tmp;

	tmp = game->enemy_moving;
	while (game->enemy_moving)
	{
		set_pos_x_sub(game);
		llist_rot(&game->enemy_moving);
		if (tmp == game->enemy_moving)
			break ;
	}
}

void	set_pos_x_sub(t_game *game)
{
	int	pos_x;
	int	pos_y;
	int	direction;

	pos_x = ((mlx_image_t *)game->enemy_moving->value)->instances->x;
	pos_y = ((mlx_image_t *)game->enemy_moving->value)->instances->y;
	if (MAP_HEIGHT - 4 * TILE_SIZE < pos_y)
		return ;
	if ((rand() % (ft_max(pos_x + pos_y, 1))) % 3)
		return ;
	direction = is_neighbours_free(game, pos_x, pos_y);
	if (direction == 1)
		pos_x -= TILE_SIZE;
	if (direction == 2)
		pos_x += TILE_SIZE;
	if (direction == 3)
	{
		if ((rand() % (ft_max(pos_x + pos_y, 1))) % 2)
			pos_x -= TILE_SIZE;
		else
			pos_x += TILE_SIZE;
	}
	((mlx_image_t *)game->enemy_moving->value)->instances->x = pos_x;
}

/*
direction:
	0:	not free
	1:	left is free
	2:	right is free
	3:	both are free
*/
int	is_neighbours_free(t_game *game, int pos_x, int pos_y)
{
	int	direction;

	direction = 0;
	if (is_left_free(game->collectible, pos_x, pos_y) \
		&& is_left_free(game->enemy_static, pos_x, pos_y) \
		&& is_left_free(game->enemy_moving, pos_x, pos_y))
		direction += 1;
	if (is_right_free(game->collectible, pos_x, pos_y) \
		&& is_right_free(game->enemy_static, pos_x, pos_y) \
		&& is_right_free(game->enemy_moving, pos_x, pos_y))
		direction += 2;
	return (direction);
}

int	is_left_free(t_llist *llist, int pos_x, int pos_y)
{
	t_llist	*tmp;

	if (pos_x - TILE_SIZE < 2 * TILE_SIZE)
		return (0);
	tmp = llist;
	while (llist)
	{
		if (((mlx_image_t *)llist->value)->instances->enabled == true \
			&& ((mlx_image_t *)llist->value)->instances->x == pos_x - TILE_SIZE
			&& ((mlx_image_t *)llist->value)->instances->y == pos_y)
			return (0);
		llist_rot(&llist);
		if (tmp == llist)
			break ;
	}
	return (1);
}

int	is_right_free(t_llist *llist, int pos_x, int pos_y)
{
	t_llist	*tmp;

	if (MAP_WIDTH - 3 * TILE_SIZE < pos_x + TILE_SIZE)
		return (0);
	tmp = llist;
	while (llist)
	{
		if (((mlx_image_t *)llist->value)->instances->enabled == true \
			&& ((mlx_image_t *)llist->value)->instances->x == pos_x + TILE_SIZE
			&& ((mlx_image_t *)llist->value)->instances->y == pos_y)
			return (0);
		llist_rot(&llist);
		if (tmp == llist)
			break ;
	}
	return (1);
}
