/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_dashboard_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:39:18 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 20:07:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	str_img_dashboard_speed(t_game *game, char **dashboard_str)
{
	int		i;
	int		j;
	char	*str;

	str = ft_itoa(game->speed * 20);
	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		(*dashboard_str)[9 - i] = str[j - i - 1];
		i++;
	}
	free(str);
}

void	str_img_dashboard_collectible_curr(t_game *game, char **dashboard_str)
{
	int		i;
	int		j;
	char	*str;

	if (game->length_collectible_orig < 100)
	{
		str = ft_itoa(
				game->length_collectible_orig - game->length_collectible_curr);
		i = 0;
		j = ft_strlen(str);
		while (i < j)
		{
			(*dashboard_str)[25 - i] = str[j - i - 1];
			i++;
		}
		free(str);
	}
}

void	str_img_dashboard_collectible_orig(t_game *game, char **dashboard_str)
{
	int		i;
	int		j;
	char	*str;

	if (game->length_collectible_orig < 100)
	{
		str = ft_itoa(game->length_collectible_orig);
		i = 0;
		j = ft_strlen(str);
		while (i < j)
		{
			(*dashboard_str)[28 - i] = str[j - i - 1];
			i++;
		}
		free(str);
	}
}

void	str_img_dashboard_time(t_game *game, char **dashboard_str)
{
	int		i;
	int		j;
	char	*str;

	if (game->time_elapsed > 9999999)
		game->time_elapsed = 9999999;
	str = ft_itoa(game->time_elapsed / 1000);
	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		(*dashboard_str)[41 - i] = str[j - i - 1];
		i++;
	}
	free(str);
	str = ft_itoa(game->time_elapsed / 100);
	j = ft_strlen(str);
	(*dashboard_str)[43] = str[j - 1];
	free(str);
}
