/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_music.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:56:44 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/15 01:53:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MUSIC/miniaudio.h"

void	init_music_honk(t_game *game)
{
	play_music_honk(game);
	free_music_honk(game);
}

void	play_music_honk(t_game *game)
{
	ma_engine_init(NULL, &game->engine_honk);
	ma_engine_play_sound(&game->engine_honk, MUSIC_HONK, NULL);
}

void	play_music_win(t_game *game)
{
	char	*path_music;

	path_music = MUSIC_POLICE;
	if (game->img_price_win->instances->y == MSG_Y_EXTRA)
		path_music = MUSIC_WIN;
	ma_engine_init(NULL, &game->engine_win);
	ma_engine_play_sound(&game->engine_win, path_music, NULL);
	game->music_win = 0;
}

void	free_music_honk(t_game *game)
{
	ma_engine_uninit(&game->engine_honk);
}

void	free_music_win(t_game *game)
{
	ma_engine_uninit(&game->engine_win);
}
