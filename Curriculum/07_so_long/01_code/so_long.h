/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/23 21:53:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAP_WIDTH	450
# define MAP_HEIGHT	500

# define IMG_WIDTH	50
# define IMG_HEIGHT	50

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
	mlx_image_t	*car;
	t_llist		*road;
	t_llist		*traffic;
	int			speed;
	int			time_last;
	int			time_delta;
}	t_game;

// llist_00.c
t_llist	*llist_create(void *value);
void	llist_add(t_llist **head, t_llist *node);
t_llist	*llist_del(t_llist **head);
void	llist_free(t_llist **head);

// llist_01.c
void	llist_rot(t_llist **head);
void	llist_rrot(t_llist **head);
void	llist_print(t_llist *head);

// map.c
t_llist	*read_map(int fd);
void	prep_map(t_llist **map);

// ft*.c
void	ft_putstr(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

// *demo.c
void	so_long_demo(void);

// time.c
int		get_time_current(void);
int		get_time_elapsed(int time);
int		eat_time(int time);

// 00_game.c
void	init_game(t_game *game);
void	loop_game(t_game *game);
void	move_game(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	loop_hook(void *param);

// 01_car.c
void	init_car(t_game *game);
void	move_car(t_game *game);
void	free_car(t_game *game);

// 02_road.c
void	init_road(t_game *game);
void	move_road(t_game *game);
void	free_road(t_game *game);

// 01_traffic.c
void	init_traffic(t_game *game);
void	move_traffic(t_game *game);
void	free_traffic(t_game *game);

#endif
