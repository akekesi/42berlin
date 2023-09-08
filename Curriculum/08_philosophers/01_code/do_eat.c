/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 22:08:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_eat(t_phil **phil)
{
	if (is_death(phil))
		return ;
	if ((*phil)->n % 2)
	{
		get_fork_left(phil);
		if (is_death(phil))
			return ;
		get_fork_right(phil);
	}
	else
	{
		get_fork_right(phil);
		if (is_death(phil))
			return ;
		get_fork_left(phil);
	}
	(*phil)->time_rest = (*phil)->time_die;
	if (is_death(phil))
		return ;
	print(phil, "is eating");
	do_usleep(phil, (*phil)->time_eat);
	let_fork_left(phil);
	let_fork_right(phil);
}

void	get_fork_left(t_phil **phil)
{
	int				time_0;
	int				time_1;

	time_0 = get_time_current();
	while (1)
	{
		time_0 = set_time(phil, time_0);
		if (time_0 < 0)
			return ;
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
	int				time_0;
	int				time_1;

	time_0 = get_time_current();
	while (1)
	{
		time_0 = set_time(phil, time_0);
		if (time_0 < 0)
			return ;
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
