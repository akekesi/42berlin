/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 06:07:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_eat(t_phil **phil)
{
	if ((*phil)->id % 2)
	{
		get_fork_left(phil);
		if (!is_death(phil))
			get_fork_right(phil);
	}
	else
	{
		if ((*phil)->first_loop)
		{
			eat_time(phil, 1000);
			(*phil)->first_loop = 0;
		}
		get_fork_right(phil);
		if (!is_death(phil))
			get_fork_left(phil);
	}
	if (is_death(phil))
		return ;
	(*phil)->time_rest = (*phil)->time_die;
	print(phil, get_time_elapsed((*phil)->info->time_0), "is eating");
	eat_time(phil, (*phil)->time_eat);
	let_fork_left(phil);
	let_fork_right(phil);
}

void	get_fork_left(t_phil **phil)
{
	while (1)
	{
		if (is_death(phil))
			return ;
		if (!eat_time(phil, 1))
			return ;
		pthread_mutex_lock(&(*phil)->left->lock);
		if ((*phil)->left->free)
		{
			(*phil)->left->free = 0;
			print(
				phil,
				get_time_elapsed((*phil)->info->time_0),
				"has taken a fork");
			pthread_mutex_unlock(&(*phil)->left->lock);
			break ;
		}
		pthread_mutex_unlock(&(*phil)->left->lock);
	}
}

void	get_fork_right(t_phil **phil)
{
	while (1)
	{
		if (is_death(phil))
			return ;
		if (!eat_time(phil, 1))
			return ;
		pthread_mutex_lock(&(*phil)->right->lock);
		if ((*phil)->right->free)
		{
			(*phil)->right->free = 0;
			print(
				phil,
				get_time_elapsed((*phil)->info->time_0),
				"has taken a fork");
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
