/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/30 23:56:32 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE	50
# define MAP_WIDTH	450
# define MAP_HEIGHT	500

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
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
	mlx_image_t	*img_player;
	mlx_image_t	*img_price;
	mlx_image_t	*img_start;
	mlx_image_t	*img_stop;
	mlx_image_t	*img_win;
	mlx_image_t	*img_lose;
	t_llist		*map;
	t_llist		*road;
	t_llist		*enemy;
	t_llist		*collectible;
	int			start_stop;
	int			won;
	int			speed;
	int			time_last;
	int			time_delta;
	int			length_map;
	int			length_collectible;
}	t_game;

// 00_game.c
void	init_game(t_game *game, char *path_map);
void	loop_game(t_game *game);
void	move_game(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	loop_hook(void *param);

// 01_map.c
t_llist	*read_map(int fd);
void	free_map(t_game *game);

// 02_player.c
void	init_img_player(t_game *game);
void	move_img_player(t_game *game);
void	free_img_player(t_game *game);

// 03_price.c
void	init_img_price(t_game *game);
void	move_img_price(t_game *game);
void	find_img_price(t_game *game);
void	free_img_price(t_game *game);

// 04_start_stop.c
void	init_img_start(t_game *game);
void	init_img_stop(t_game *game);
void	free_img_start(t_game *game);
void	free_img_stop(t_game *game);

// 05_win_lose.c
void	init_img_win(t_game *game);
void	init_img_lose(t_game *game);
void	free_img_win(t_game *game);
void	free_img_lose(t_game *game);

// 06_road.c
void	init_road(t_game *game);
void	move_road(t_game *game);
void	free_road(t_game *game);

// 07_enemy.c
void	init_enemy(t_game *game);
void	move_enemy(t_game *game);
void	find_enemy(t_game *game);
void	free_enemy(t_game *game);

// 08_collectible.c
void	init_collectible(t_game *game);
void	move_collectible(t_game *game);
void	find_collectible(t_game *game);
void	free_collectible(t_game *game);

// 09_check*.c
int		check_map_00(t_game *game);
int		check_map_01(t_game *game);
int		check_map_02(t_game *game);
int		check_map_03(t_game *game);
int		check_map_04(t_game *game);
int		check_map_05(t_game *game);
int		check_map_05_sub(char c);
int		check_map_06(t_game *game);
int		check_map_06_sub1(t_game *game, int i_map, int i_line);
int		check_map_06_sub2(char *line, int i_line);

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

// time.c
int		get_time_current(void);
int		get_time_elapsed(int time);

#endif
