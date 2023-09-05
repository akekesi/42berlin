/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/05 20:11:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
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
	unsigned int	n;
	t_fork			*left;
	t_fork			*right;
}	t_phil;

typedef struct s_main
{
	int				n;
	pthread_mutex_t	fork;
}	t_main;

// philosophers.c with main
void	make_forks(t_fork **forks, unsigned int n);
void	free_forks(t_fork **forks, unsigned int n);
void	make_phils(t_phil **phils, unsigned int n, t_fork **forks);
void	free_phils(t_phil **phils);

// ft*.c
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

#endif
