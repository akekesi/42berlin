/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/19 17:32:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_llist	*map;
	t_llist	*map_track;
	t_llist	*map_finish;
	t_llist	*node;

	if (argc == 2)
	{
		// open map_start.ber
		fd = open("map_start.ber", O_RDONLY);
		if (fd < 0)
			return (0);
		map = read_map(fd);
		prep_map(&map);

		// open map_track.ber
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		map_track = read_map(fd);
		prep_map(&map_track);

		// open map_finish.ber
		fd = open("map_finish.ber", O_RDONLY);
		if (fd < 0)
			return (0);
		map_finish = read_map(fd);
		prep_map(&map_finish);

		// print start
		ft_putstr("\n");
		ft_putstr("map_original:\n");
		llist_print(map);

		// print track
		ft_putstr("\n");
		ft_putstr("map_track:\n");
		i = 26;
		while (i--)
		{
			node = llist_del(&map);
			llist_free(&node);
			llist_rrot(&map_track);
			node = llist_create(ft_strdup(map_track->line));
			llist_add(&map, node);
			llist_rrot(&map);
			llist_print(map);
			ft_putstr("\n");
		}

		// print finish
		ft_putstr("\n");
		ft_putstr("map_finish:\n");
		i = 10;
		while (i--)
		{
			if (map_finish)
			{
				node = llist_del(&map);
				llist_free(&node);
				node = llist_del(&map_finish);
				llist_add(&map, node);
			}
			llist_rrot(&map);
			llist_print(map);
			ft_putstr("\n");
		}
		llist_free(&map);
		llist_free(&map_track);
	}
	else
		ft_putstr("Error");
	test_mlx42_00();
}
