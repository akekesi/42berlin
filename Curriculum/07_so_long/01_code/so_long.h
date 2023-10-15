/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/15 02:37:18 by akekesi          ###   ########.fr       */
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
# include "MUSIC/miniaudio.h"

# define TILE_SIZE				50
# define MAP_WIDTH				450
# define MAP_HEIGHT				500
# define MSG_WIDTH				220
# define MSG_HEIGHT				15
# define MSG_X					115
# define MSG_Y					117
# define MSG_X_EXTRA			200
# define MSG_Y_EXTRA			133
# define DASHBOARD_X			0
# define DASHBOARD_Y			478
# define LAYER_ROAD				0
# define LAYER_FINISH			1
# define LAYER_OTHERS			2
# define LAYER_PLAYER			3
# define LAYER_CRASH			4
# define LAYER_MSG				5

# define INFO					"\nFake Road Fighter \
\n--> https://en.wikipedia.org/wiki/Road_Fighter \
\n--> https://www.youtube.com/watch?app=desktop&v=5Q5-QNfmsbQ \
\n--> https://media.cdnandroid.com/item_images/672948/imagen-road-fighter-car-racing-0ori.jpg \
\n--> https://img.itch.zone/aW1hZ2UvNzU2MTE3LzQyMzA2NDQucG5n/original/ePLeSD.png \
\n--> https://www.youtube.com/watch?v=iFPBhBRMyfw \
\n--> https://www.youtube.com/watch?v=9ZrAYxWPN6c \
\n--> https://www.youtube.com/watch?v=BsrqKE1iqqo \
\n--> https://www.photopea.com/ \
\n--> https://fontmeme.com/pixel-fonts/ font: ABSTRACT \
\n--> https://www.imgonline.com.ua/eng/replace-color-result.php \
\n--> https://y2down.cc/de/youtube-wav.html \
\n--> https://github.com/codam-coding-college/MLX42 \
\n--> https://github.com/mackron/miniaudio \
\n\n"
# define TITLE					"Fake Road Fighter"
# define DASHBOARD_STR			"speed:   0km/h | score:  0/ 0 | time:    0.0s"

# define PATH_PLAYER			"assets/images/player.png"
# define PATH_CRASH				"assets/images/crash.png"
# define PATH_FINISH			"assets/images/finish.png"
# define PATH_PRICE				"assets/images/price.png"
# define PATH_START				"assets/images/msg_start.png"
# define PATH_STOP				"assets/images/msg_stop.png"
# define PATH_WIN				"assets/images/msg_win.png"
# define PATH_WIN_QUESTION		"assets/images/msg_win_question.png"
# define PATH_LOSE				"assets/images/msg_lose.png"
# define PATH_DASHBOARD			"assets/images/dashboard.png"
# define PATH_ROAD				"assets/images/road_line_0X.png"
# define PATH_POLICE_RED		"assets/images/police_red.png"
# define PATH_POLICE_BLUE		"assets/images/police_blue.png"
# define PATH_POLICE_ORIG		"assets/images/police_orig.png"
# define PATH_COLLECTIBLE		"assets/images/collectible.png"
# define PATH_ENEMY_BLUE		"assets/images/enemy_blue.png"
# define PATH_ENEMY_ORANGE		"assets/images/enemy_orange.png"
# define PATH_ENEMY_PURPLE		"assets/images/enemy_purple.png"
# define PATH_ENEMY_YELLOW		"assets/images/enemy_yellow.png"
# define PATH_ENEMY_TRUCK_FRONT	"assets/images/enemy_truck_front.png"
# define PATH_ENEMY_TRUCK_REAR	"assets/images/enemy_truck_rear.png"

# define MINIAUDIO_IMPLEMENTATION
# define MUSIC_HONK		"assets/music/car_horn_sound_effect_01s.wav"
# define MUSIC_POLICE	"assets/music/krs_one_sound_of_da_police_short.wav"
# define MUSIC_WIN		"assets/music/war_low_rider_short.wav"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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
	mlx_image_t	*img_win_question;
	mlx_image_t	*img_lose;
	mlx_image_t	*img_dashboard_bgr;
	mlx_image_t	*img_dashboard_str;
	t_llist		*map;
	t_llist		*road;
	t_llist		*police;
	t_llist		*collectible;
	t_llist		*enemy_static;
	t_llist		*enemy_moving;
	int			start_stop;
	int			speed;
	int			time_last;
	int			time_rest;
	int			time_move;
	int			time_delta;
	int			time_elapsed;
	int			time_finish;
	int			length_map_orig;
	int			length_map_curr;
	int			length_collectible_curr;
	int			length_collectible_orig;
	int			length_moves;
	int			music_honk;
	int			music_win;
	ma_engine	engine_honk;
	ma_engine	engine_win;
}	t_game;

// so_loong.c with main
void			init_sub(t_game *game);
void			free_sub(t_game *game);

// 00_game_*.c
void			init_game(t_game *game);
void			init_game_sub1(t_game *game);
void			init_game_sub2(t_game *game);
void			loop_game(t_game *game);
void			loop_hook(void *param);
void			loop_hook_sub1(t_game *game);
void			loop_hook_sub2(t_game *game);
void			loop_hook_sub3(t_game *game);
void			key_hook(mlx_key_data_t keydata, void *param);
void			key_hook_sub1(t_game *game);
void			key_hook_sub2(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub3(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub4(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub5(mlx_key_data_t keydata, t_game *game);
void			key_hook_sub6(mlx_key_data_t keydata, t_game *game);
void			write_win(t_game *game);
void			write_lose(void);

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

// 15_win_lose_*.c
void			init_img_win(t_game *game);
void			init_img_win_question(t_game *game);
void			init_img_lose(t_game *game);
void			free_img_win(t_game *game);
void			free_img_win_question(t_game *game);
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

// 20_map_*.c
t_llist			*read_map(char *path_map);
void			free_map(t_game *game);
char			**get_map_matrix(t_game *game);
void			get_map_matrix_sub(
					t_game *game, char **map_matrix, t_point size);
void			print_map_matrix(char **map_matrix, t_point size);
void			free_map_matrix(char **map_matrix, t_point size);

// 21_road.c
void			init_road(t_game *game);
void			move_road(t_game *game);
void			free_road(t_game *game);

// 22_police.c
void			init_police(t_game *game);
void			init_police_sub(t_game *game, char *path_png);
void			move_police(t_game *game);
void			free_police(t_game *game);

// 23_collectible.c
void			init_collectible(t_game *game);
void			init_collectible_sub(t_game *game, int row, int col);
void			move_collectible(t_game *game);
void			find_collectible(t_game *game);
void			free_collectible(t_game *game);

// 24_enemy_static*.c
void			init_enemy_static(t_game *game);
void			init_enemy_static_sub(
					t_game *game, int row, int col, int *truck);
mlx_texture_t	*rand_enemy_static(int truck, int row, int col);
void			move_enemy_static(t_game *game);
void			free_enemy_static(t_game *game);
void			find_enemy_static_front(t_game *game);
void			find_enemy_static_left(t_game *game);
void			find_enemy_static_right(t_game *gameoving);

// 25_enemy_moving*.c
void			init_enemy_moving(t_game *game);
void			init_enemy_moving_sub(t_game *game, int row, int col);
mlx_texture_t	*rand_enemy_moving(int row, int col);
void			move_enemy_moving(t_game *game);
void			free_enemy_moving(t_game *game);
void			set_pos_x(t_game *game);
int				is_neighbours_free(t_game *game, int pso_x, int pos_y);
int				is_left_free(t_llist *llist, int pos_x, int pos_y);
int				is_right_free(t_llist *llist, int pos_x, int pos_y);
void			find_enemy_moving_front(t_game *game);
void			find_enemy_moving_left(t_game *game);
void			find_enemy_moving_right(t_game *game);

// 30_music.c
void			init_music_honk(t_game *game);
void			play_music_honk(t_game *game);
void			free_music_honk(t_game *game);
void			play_music_win(t_game *game);
void			free_music_win(t_game *game);

// 40_check_*.c
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
int				check_map_06_sub(char **map_matrix, t_point size);
int				check_map_07(t_game *game);
int				check_map_07_sub1(
					t_game *game, char **map_matrix, t_point size);
int				check_map_07_sub2(t_game *game, int row, int col);

// flood_fill.c
void			flood_fill(
					char **map_matrix,
					t_point size,
					t_point start,
					char no_stream);
void			flood_fill_sub1(
					char **map_matrix,
					t_point size,
					t_point start,
					char no_stream);
void			flood_fill_sub2(
					char **map_matrix,
					t_point size,
					t_point start,
					char no_stream);
void			flood_fill_sub3(
					char **map_matrix,
					t_point size,
					t_point start,
					char no_stream);
void			flood_fill_sub4(
					char **map_matrix,
					t_point size,
					t_point start,
					char no_stream);

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
