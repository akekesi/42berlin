/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/13 20:40:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	do_eat(t_phil **phil)
{
	if ((*phil)->id % 2)
	{
		if (!get_fork_left(phil))
			return (0);
		if (!get_fork_right(phil))
			return (0);
	}
	else
	{
		if ((*phil)->first_loop)
		{
			eat_time(phil, 10);
			(*phil)->first_loop = 0;
		}
		if (!get_fork_right(phil))
			return (0);
		if (!get_fork_left(phil))
			return (0);
	}
	print(phil, "is eating");
	(*phil)->time_rest = (*phil)->time_die;
	eat_time(phil, (*phil)->time_eat);
	let_fork_left(phil);
	let_fork_right(phil);
	return (1);
}

int	get_fork_left(t_phil **phil)
{
	long long	time;

	time = get_time_current();
	while (get_time_elapsed(time) < (*phil)->time_rest)
	{
		pthread_mutex_lock(&(*phil)->left->lock);
		if ((*phil)->left->free)
		{
			(*phil)->left->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->left->lock);
			(*phil)->time_rest -= get_time_elapsed(time);
			return (1);
		}
		pthread_mutex_unlock(&(*phil)->left->lock);
		if (is_death(phil))
			return (0);
		usleep(1);
	}
	do_die(phil);
	return (0);
}

int	get_fork_right(t_phil **phil)
{
	long long	time;

	time = get_time_current();
	while (get_time_elapsed(time) < (*phil)->time_rest)
	{
		pthread_mutex_lock(&(*phil)->right->lock);
		if ((*phil)->right->free)
		{
			(*phil)->right->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->right->lock);
			(*phil)->time_rest -= get_time_elapsed(time);
			return (1);
		}
		pthread_mutex_unlock(&(*phil)->right->lock);
		if (is_death(phil))
			return (0);
		usleep(1);
	}
	do_die(phil);
	return (0);
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
