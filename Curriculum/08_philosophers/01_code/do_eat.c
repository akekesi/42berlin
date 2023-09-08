/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 14:38:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_eat(t_phil **phil)
{
	if ((*phil)->n % 2)
	{
		get_fork_left(phil);
		get_fork_right(phil);
	}
	else
	{
		get_fork_right(phil);
		get_fork_left(phil);
	}
	(*phil)->time_rest += (*phil)->time_die;
	print(phil, "is eating");
	do_usleep(phil, (*phil)->time_eat);
	let_fork_left(phil);
	let_fork_right(phil);
}

void	get_fork_left(t_phil **phil)
{
	struct timeval	time;
	int				time_0;
	int				time_1;

	gettimeofday(&time, NULL);
	time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (1)
	{
		time_1 = get_time(time_0);
		if (10 < time_1)
		{
			// printf("----->%d %d %d\n", (*phil)->n, (*phil)->time_rest, time_1);
			if (check_die(phil))
				return ;
			if ((*phil)->time_rest < time_1)
			{
				pthread_mutex_lock(&(*phil)->info->lock);
				(*phil)->info->die = 1;
				pthread_mutex_unlock(&(*phil)->info->lock);
				print(phil, "died");
				(*phil)->time_rest = 0;
				return ;
			}
			(*phil)->time_rest -= time_1;
			gettimeofday(&time, NULL);
			time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
		}
		pthread_mutex_lock(&(*phil)->left->lock);
		if ((*phil)->left->free)
		{
			(*phil)->left->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->left->lock);
			break ;
		}
		pthread_mutex_unlock(&(*phil)->left->lock);
	}
}

void	get_fork_right(t_phil **phil)
{
	struct timeval	time;
	int				time_0;
	int				time_1;

	gettimeofday(&time, NULL);
	time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (1)
	{
		time_1 = get_time(time_0);
		if (10 < time_1)
		{
			// printf("--THIS--->%d %d\n", (*phil)->time_rest, time_1);
			if (check_die(phil))
				return ;
			if ((*phil)->time_rest < time_1)
			{
				pthread_mutex_lock(&(*phil)->info->lock);
				(*phil)->info->die = 1;
				pthread_mutex_unlock(&(*phil)->info->lock);
				print(phil, "died");
				(*phil)->time_rest = 0;
				return ;
			}
			(*phil)->time_rest -= time_1; 
			gettimeofday(&time, NULL);
			time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
		}
		pthread_mutex_lock(&(*phil)->right->lock);
		if ((*phil)->right->free)
		{
			(*phil)->right->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->right->lock);
			break ;
		}
		pthread_mutex_unlock(&(*phil)->right->lock);
	}
}

void	let_fork_left(t_phil **phil)
{
	pthread_mutex_lock(&(*phil)->left->lock);
	(*phil)->left->free = 1;
	pthread_mutex_unlock(&(*phil)->left->lock);
}

void	let_fork_right(t_phil **phil)
{
	pthread_mutex_lock(&(*phil)->right->lock);
	(*phil)->right->free = 1;
	pthread_mutex_unlock(&(*phil)->right->lock);
}
