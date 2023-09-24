/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 20:56:20 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE	50
# define MAP_WIDTH	450
# define MAP_HEIGHT	500

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "get_next_line_bonus.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_llist
{
	void			*value;
	struct s_llist	*prev;
	struct s_llist	*next;
}	t_llist;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*win;
	t_llist		*map;
	t_llist		*road;
	t_llist		*enemy;
	t_llist		*collectible;
	int			speed;
	int			time_last;
	int			time_delta;
	int			length_map;
}	t_game;

// 00_time.c
int		get_time_current(void);
int		get_time_elapsed(int time);

// 01_game.c
void	init_game(t_game *game, char *path_map);
void	loop_game(t_game *game);
void	move_game(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	loop_hook(void *param);

// 02_map.c
t_llist	*read_map(int fd);

// 03_player.c
void	init_player(t_game *game);
void	move_player(t_game *game);
void	free_player(t_game *game);

// 04_win.c
void	init_win(t_game *game);
void	move_win(t_game *game);
void	free_win(t_game *game);

// 05_road.c
void	init_road(t_game *game);
void	move_road(t_game *game);
void	free_road(t_game *game);

// 06_enemy.c
void	init_enemy(t_game *game);
void	move_enemy(t_game *game);
void	free_enemy(t_game *game);

// 07_collectible.c
void	init_collectible(t_game *game);
void	move_collectible(t_game *game);
void	free_collectible(t_game *game);

// ft*.c
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	ft_putstr(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

// llist_00.c
t_llist	*llist_create(void *value);
void	llist_add(t_llist **head, t_llist *node);
t_llist	*llist_del(t_llist **head);
void	llist_free(t_llist **head);

// llist_01.c
void	llist_rot(t_llist **head);
void	llist_rrot(t_llist **head);
int		llist_len(t_llist *head);
void	llist_print(t_llist *head);

#endif
