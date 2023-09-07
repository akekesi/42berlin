/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 19:21:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_eat(t_phil **phil)
{
	if ((*phil)->n % 2)
		do_eat_sub1(phil);
	else
		do_eat_sub2(phil);
	print(phil, "is eating");
	usleep((*phil)->time_eat * 1000);
	pthread_mutex_lock(&(*phil)->left->lock);
	(*phil)->left->free = 1;
	pthread_mutex_unlock(&(*phil)->left->lock);
	pthread_mutex_lock(&(*phil)->right->lock);
	(*phil)->right->free = 1;
	pthread_mutex_unlock(&(*phil)->right->lock);
}

void	do_eat_sub1(t_phil **phil)
{
	while (1)
	{
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
	while (1)
	{
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

void	do_eat_sub2(t_phil **phil)
{
	while (1)
	{
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
	while (1)
	{
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
