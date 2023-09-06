/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 18:39:14 by akekesi          ###   ########.fr       */
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

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_phil
{
	int				n;
	t_fork			*left;
	t_fork			*right;
	pthread_mutex_t	*print;
}	t_phil;

typedef struct s_info
{
	int				n;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_eat;
	t_fork			*forks;
	t_phil			*phils;
	pthread_t		*threads;
	pthread_mutex_t	print;
}	t_info;

// fork.c
void		make_forks(t_fork **forks, int n);
void		free_forks(t_fork **forks, int n);

// phil.c
void		make_phils(t_phil **phils, int n, t_fork **forks);
void		free_phils(t_phil **phils);

// thread.c
void		make_threads(pthread_t **threads, int n);
void		free_threads(pthread_t **threads);
void		start_threads(t_info **info, int n);
void		join_threads(pthread_t **threads, int n);

// routine.c
void		*routine(void *arg);

// info.c
void		init_info(int argc, char **argv, t_info **info);
void		init_info_sub1(
				t_fork **forks, t_phil **phils, pthread_t **threads, int n);
void		init_info_sub2(t_info **info, int n);
void		free_info(t_info **info);

// print.c
void		print(t_phil **phil, char *message);

// ft*.c
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

#endif
