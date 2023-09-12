/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 22:36:19 by akekesi          ###   ########.fr       */
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
		{
			let_fork_left(phil);
			return (0);
		}
	}
	else
	{
		if ((*phil)->first_loop)
		{
			eat_time(phil, 10000);
			(*phil)->first_loop = 0;
		}
		if (!get_fork_right(phil))
			return (0);
		if (!get_fork_left(phil))
		{
			let_fork_right(phil);
			return (0);
		}
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
	while (1)
	{
		pthread_mutex_lock(&(*phil)->left->lock);
		if ((*phil)->left->free)
		{
			(*phil)->left->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->left->lock);
			return (1);
		}
		pthread_mutex_unlock(&(*phil)->left->lock);
		if (!eat_time(phil, 1))
			return (0);
	}
}

int	get_fork_right(t_phil **phil)
{
	while (1)
	{
		pthread_mutex_lock(&(*phil)->right->lock);
		if ((*phil)->right->free)
		{
			(*phil)->right->free = 0;
			print(phil, "has taken a fork");
			pthread_mutex_unlock(&(*phil)->right->lock);
			return (1);
		}
		pthread_mutex_unlock(&(*phil)->right->lock);
		if (!eat_time(phil, 1))
			return (0);
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
