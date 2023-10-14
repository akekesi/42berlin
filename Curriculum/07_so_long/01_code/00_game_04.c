/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/14 20:22:51 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_win(t_game *game)
{
	char	*str;

	ft_putstr("time: ");
	str = ft_itoa(game->time_finish / 1000);
	ft_putstr(str);
	free(str);
	ft_putstr(".");
	str = ft_itoa(game->time_finish / 100);
	ft_putstr(&str[ft_strlen(str) - 1]);
	free(str);
	ft_putstr("s\n");
	if (game->img_price_win->instances->y > 0)
	{
		ft_putstr("***************\n");
		ft_putstr("*** YOU WIN ***\n");
		ft_putstr("***************\n");
	}
	else
	{
		ft_putstr("???????????????\n");
		ft_putstr("??? YOU WIN ???\n");
		ft_putstr("???????????????\n");
	}
}

void	write_lose(void)
{
	ft_putstr(">>> YOU LOSE <<<\n");
}
