/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:56:44 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/12 22:44:21 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MUSIC/miniaudio.h"

void	play_music_police(t_game *game)
{
	ma_engine_init(NULL, &game->engine_police);
	ma_engine_play_sound(&game->engine_police, MUSIC_POLICE, NULL);
}

void	free_music_police(t_game *game)
{
	ma_engine_uninit(&game->engine_police);
}

void	play_music_honk(t_game *game)
{
	ma_engine_init(NULL, &game->engine_honk);
	ma_engine_play_sound(&game->engine_honk, MUSIC_POLICE, NULL);
}

void	free_music_honk(t_game *game)
{
	ma_engine_uninit(&game->engine_honk);
}
