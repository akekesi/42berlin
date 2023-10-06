/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/06 22:07:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "get_next_line_bonus.h"
# include "MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE				50
# define MAP_WIDTH				450
# define MAP_HEIGHT				500
# define MSG_WIDTH				220
# define MSG_HEIGHT				15
# define MSG_X					115
# define MSG_Y					117
# define DASHBOARD_X			0
# define DASHBOARD_Y			478
# define LAYER_ROAD				0
# define LAYER_FINISH			1
# define LAYER_OTHERS			2
# define LAYER_PLAYER			3
# define LAYER_CRASH			4
# define LAYER_MSG				5

# define INFO					"\nCopy of Road Fighter \
\n--> https://en.wikipedia.org/wiki/Road_Fighter \
\n--> https://www.youtube.com/watch?app=desktop&v=5Q5-QNfmsbQ \
\n--> https://media.cdnandroid.com/item_images/672948/ \
imagen-road-fighter-car-racing-0ori.jpg\n\n"
# define TITLE					"Fake Road Fighter"
# define DASHBOARD_STR			"speed:   0km/h | score:  0/ 0 | time:    0.0s"

// https://www.photopea.com/
// https://fontmeme.com/pixel-fonts/
// font: ABS
# define PATH_PLAYER			"assets/images/player.png"
# define PATH_CRASH				"assets/images/crash.png"
# define PATH_FINISH			"assets/images/finish.png"
# define PATH_PRICE				"assets/images/price.png"
# define PATH_START				"assets/images/msg_start.png"
# define PATH_STOP				"assets/images/msg_stop.png"
# define PATH_WIN				"assets/images/msg_win.png"
# define PATH_LOSE				"assets/images/msg_lose.png"
# define PATH_DASHBOARD			"assets/images/dashboard.png"
# define PATH_ROAD				"assets/images/road_line_0X.png"
# define PATH_ENEMY_TRUCK_FRONT	"assets/images/enemy_truck_front.png"
# define PATH_ENEMY_TRUCK_REAR	"assets/images/enemy_truck_rear.png"
# define PATH_ENEMY_BLUE		"assets/images/enemy_blue.png"
# define PATH_ENEMY_YELLOW		"assets/images/enemy_yellow.png"
# define PATH_COLLECTIBLE		"assets/images/collectible.png"

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
	mlx_image_t	*img_crash;
	mlx_image_t	*img_finish;
	mlx_image_t	*img_price;
	mlx_image_t	*img_price_win;
	mlx_image_t	*img_start;
	mlx_image_t	*img_stop;
	mlx_image_t	*img_win;
	mlx_image_t	*img_lose;
	mlx_image_t	*img_dashboard_bgr;
	mlx_image_t	*img_dashboard_str;
	t_llist		*map;
	t_llist		*road;
	t_llist		*enemy;
	t_llist		*collectible;
	int			start_stop;
	int			speed;
	int			time_last;
	int			time_rest;
	int			time_move;
	int			time_delta;
	int			time_elapsed;
	int			length_map;
	int			length_collectible_curr;
	int			length_collectible_orig;
	int			length_moves;
}	t_game;

// so_loong.c with main
void			init_sub(t_game *game);
void			free_sub(t_game *game);

// 00_game.c
void			init_game(t_game *game);
void			init_game_sub(t_game *game);
void			loop_game(t_game *game);
void			loop_hook(void *param);
void			loop_hook_sub1(t_game *game);
void			loop_hook_sub2(t_game *game);
void			write_win(t_game *game);
void			key_hook(mlx_key_data_t keydata, void *param);
void			key_hook_sub1(t_game *game);
void			key_hook_sub2(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub3(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub4(mlx_key_data_t keydata, t_game *game);

// 10_player.c
void			init_img_player(t_game *game);
void			move_img_player(t_game *game);
void			free_img_player(t_game *game);

// 11_crash.c
void			init_img_crash(t_game *game);
void			move_img_crash(t_game *game);
void			find_img_crash(t_game *game);
void			free_img_crash(t_game *game);

// 12_finish.c
void			init_img_finish(t_game *game);
void			move_img_finish(t_game *game);
void			find_img_finish(t_game *game);
void			free_img_finish(t_game *game);

// 13_price.c
void			init_img_price(t_game *game);
void			move_img_price(t_game *game);
void			find_img_price(t_game *game);
void			free_img_price(t_game *game);

// 14_start_stop.c
void			init_img_start(t_game *game);
void			init_img_stop(t_game *game);
void			free_img_start(t_game *game);
void			free_img_stop(t_game *game);

// 15_win_lose.c
void			init_img_win(t_game *game);
void			init_img_lose(t_game *game);
void			free_img_win(t_game *game);
void			free_img_lose(t_game *game);

// 16_dashboard_*.c
void			init_img_dashboard(t_game *game);
void			move_img_dashboard(t_game *game);
void			free_img_dashboard(t_game *game);
void			str_img_dashboard_speed(t_game *game, char **dashboard_str);
void			str_img_dashboard_collectible_curr(
					t_game *game, char **dashboard_str);
void			str_img_dashboard_collectible_orig(
					t_game *game, char **dashboard_str);
void			str_img_dashboard_time(t_game *game, char **dashboard_str);

// 07_map.c
t_llist			*read_map(char *path_map);
void			free_map(t_game *game);

// 08_road.c
void			init_road(t_game *game);
void			move_road(t_game *game);
void			free_road(t_game *game);

// 09_enemy_*.c
void			init_enemy(t_game *game);
void			init_enemy_sub(t_game *game, int row, int col, int *truck);
mlx_texture_t	*rand_enemy(int truck, int row, int col);
void			move_enemy(t_game *game);
void			free_enemy(t_game *game);
void			find_enemy_front(t_game *game);
void			find_enemy_left(t_game *game);
void			find_enemy_right(t_game *game);

// 10_collectible.c
void			init_collectible(t_game *game);
void			init_collectible_sub(t_game *game, int row, int col);
void			move_collectible(t_game *game);
void			find_collectible(t_game *game);
void			free_collectible(t_game *game);

// 11_check_*.c
int				check_map(t_game *game);
int				check_map_sub1(t_game *game);
int				check_map_sub2(t_game *game);
int				check_map_00(t_game *game);
int				check_map_01(t_game *game);
int				check_map_02(t_game *game);
int				check_map_03(t_game *game);
int				check_map_04(t_game *game);
int				check_map_05(t_game *game);
int				check_map_05_sub(char c);
int				check_map_06(t_game *game);
int				check_map_06_sub1(t_game *game, int i_map, int i_line);
int				check_map_06_sub2(char *line, int i_line);

// ft*.c
char			*ft_itoa(int n);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			ft_putstr(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *str1, char *str2);
int				ft_strlen(char *str);

// llist_00.c
t_llist			*llist_create(void *value);
void			llist_add(t_llist **head, t_llist *node);
t_llist			*llist_del(t_llist **head);
void			llist_free(t_llist **head);

// llist_01.c
void			llist_rot(t_llist **head);
void			llist_rrot(t_llist **head);
int				llist_len(t_llist *head);
void			llist_print(t_llist *head);

// time.c
int				get_time_current(void);
int				get_time_elapsed(int time);

#endif
