/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_win_lose_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 17:13:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img_win(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_win);
}

void	free_img_win_question(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_win_question);
}

void	free_img_lose(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_lose);
}
