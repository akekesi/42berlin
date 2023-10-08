/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 01:57:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_win(t_game *game)
{
	char	*str;

	write(1, "time: ", 6);
	str = ft_itoa(game->time_finish / 1000);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, ".", 1);
	str = ft_itoa(game->time_finish / 100);
	write(1, &str[ft_strlen(str) - 1], 1);
	free(str);
	write(1, "s\n", 2);
	if (game->img_price_win->instances->y > 0)
	{
		write(1, "***************\n", 16);
		write(1, "*** YOU WIN ***\n", 16);
		write(1, "***************\n", 16);
	}
	else
		write(1, ">>> YOU WIN <<<\n", 16);
}

void	write_lose(void)
{
	write(1, ">>> YOU LOSE <<<\n", 17);
}
