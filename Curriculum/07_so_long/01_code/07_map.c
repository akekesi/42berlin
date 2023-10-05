/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:20:36 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 22:55:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_llist	*read_map(char *path_map)
{
	int		fd;
	char	*line;
	t_llist	*map;
	t_llist	*node;

	map = NULL;
	fd = open(path_map, O_RDONLY);
	while (-1 < fd)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
		{
			free(line);
			break ;
		}
		node = llist_create(line);
		llist_add(&map, node);
	}
	return (map);
}

void	free_map(t_game *game)
{
	llist_free(&game->map);
}