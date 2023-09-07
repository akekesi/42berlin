/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 23:08:17 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork	t_fork;
typedef struct s_phil	t_phil;
typedef struct s_main	t_main;

typedef struct s_info
{
	int				n;
	int				die;
	int				time_0;
	pthread_mutex_t	lock;
}	t_info;

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_phil
{
	int				n;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_eat;
	int				time_rest;
	t_fork			*left;
	t_fork			*right;
	t_info			*info;
}	t_phil;

// fork.c
void		make_forks(t_fork **forks, int n);
void		free_forks(t_fork **forks, int n);

// phil.c
void		make_phils_sub1(t_phil **phils, int argc, char **argv);
void		make_phils_sub2(
				t_phil **phils, t_info **info, t_fork **forks, int n);
void		free_phils(t_phil **phils);

// thread.c
void		make_threads(pthread_t **threads, int n);
void		free_threads(pthread_t **threads);
void		start_threads(pthread_t **threads, int n, t_phil **phils);
void		join_threads(pthread_t **threads, int n);

// routine.c
void		*routine(void *arg);

// info.c
void		make_info(t_info **info, int n);
void		free_info(t_info **info);

// do_eat.c
void		do_eat(t_phil **phil);
void		get_fork_left(t_phil **phil);
void		get_fork_right(t_phil **phil);
void		let_fork_left(t_phil **phil);
void		let_fork_right(t_phil **phil);

// do_sleep.c
void		do_sleep(t_phil **phil);

// do_think.c
void		do_think(t_phil **phil);

// do_die.c
void		do_die(t_phil **phil);
int			check_die(t_phil **phil);

// time.c
int			get_time(int time_0);
void		set_time(t_phil **phil);
void		do_usleep(t_phil **phil, int time);
// print.c
void		print(t_phil **phil, char *message);

// ft*.c
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

#endif
