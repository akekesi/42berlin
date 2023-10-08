/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 20:18:44 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- music
--> Outkast - Two Dope Boyz (in a Cadillac)
--> KRS-One - Sound of da Police
- error handling
- solvability:
--> talan flood fill-lel kene <-- !!!
--> atjutas, mindig legyen szabad ut
--> backwater
-->
	XCE... --> not solvable !!!
	XEE...
	X P...
--> belelog az enemy a finish/proce-ba
	1111111
	10000P1
	100EEE1
	1ME0001
	10W0001
	1111111
*/

void	init_sub(t_game *game)
{
	init_game(game);
	init_road(game);
	init_police(game);
	init_collectible(game);
	init_enemy_static(game);
	init_enemy_moving(game);
	init_img_player(game);
	init_img_crash(game);
	init_img_finish(game);
	init_img_price(game);
	init_img_start(game);
	init_img_stop(game);
	init_img_win(game);
	init_img_win_question(game);
	init_img_lose(game);
	init_img_dashboard(game);
}

void	free_sub(t_game *game)
{
	free_map(game);
	free_road(game);
	free_police(game);
	free_collectible(game);
	free_enemy_static(game);
	free_enemy_moving(game);
	free_img_player(game);
	free_img_crash(game);
	free_img_finish(game);
	free_img_price(game);
	free_img_start(game);
	free_img_stop(game);
	free_img_win(game);
	free_img_win_question(game);
	free_img_lose(game);
	free_img_dashboard(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		game.length_map = llist_len(game.map);
		if (!check_map(&game))
		{
			free_map(&game);
			return (0);
		}
		ft_putstr(INFO);
		init_sub(&game);
		loop_game(&game);
		free_sub(&game);
		mlx_terminate(game.mlx);
		ft_putstr(INFO);
	}
	else
		ft_putstr("Error\n");
}
