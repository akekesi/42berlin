/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:53:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/10 23:39:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Args:
char **map_matrix:
11111111
10001001
10010001
10110001
11100001

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
t_point size:
	size.x = 8
	size.y = 5

t_point start:
	size.x = 0
	size.y = 0

char no_stream: direction which is not allowed
	'L': no stream to left
	'R': no stream to right
	'U': no stream to up
	'D': no stream to down
	otherwise: stream to all four direction

Result:
FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
*/
void	flood_fill(
	char **map_matrix,
	t_point size,
	t_point start,
	char no_stream)
{
	t_point	start_new;

	start_new.x = 0;
	start_new.y = 0;
	if (map_matrix[start.y][start.x] == 'F')
		return ;
	if (map_matrix[start.y][start.x] == '1')
		return ;
	if (map_matrix[start.y][start.x] == 'E')
		return ;
	if (map_matrix[start.y][start.x] == 'M')
		return ;
	map_matrix[start.y][start.x] = 'F';
	flood_fill_sub1(map_matrix, size, start, no_stream);
	flood_fill_sub2(map_matrix, size, start, no_stream);
	flood_fill_sub3(map_matrix, size, start, no_stream);
	flood_fill_sub4(map_matrix, size, start, no_stream);
}

void	flood_fill_sub1(
	char **map_matrix,
	t_point size,
	t_point start,
	char no_stream)
{
	t_point	start_new;

	if (no_stream != 'L' && 0 < start.x)
	{
		start_new.x = start.x - 1;
		start_new.y = start.y;
		flood_fill(map_matrix, size, start_new, no_stream);
	}
}

void	flood_fill_sub2(
	char **map_matrix,
	t_point size,
	t_point start,
	char no_stream)
{
	t_point	start_new;

	if (no_stream != 'R' && start.x + 1 < size.x)
	{
		start_new.x = start.x + 1;
		start_new.y = start.y;
		flood_fill(map_matrix, size, start_new, no_stream);
	}
}

void	flood_fill_sub3(
	char **map_matrix,
	t_point size,
	t_point start,
	char no_stream)
{
	t_point	start_new;

	if (no_stream != 'U' && 0 < start.y)
	{
		start_new.x = start.x;
		start_new.y = start.y - 1;
		flood_fill(map_matrix, size, start_new, no_stream);
	}
}

void	flood_fill_sub4(
	char **map_matrix,
	t_point size,
	t_point start,
	char no_stream)
{
	t_point	start_new;

	if (no_stream != 'D' && start.y + 1 < size.y)
	{
		start_new.x = start.x;
		start_new.y = start.y + 1;
		flood_fill(map_matrix, size, start_new, no_stream);
	}
}
