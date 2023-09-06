/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:06:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 22:44:24 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eat(t_phil **phil)
{
	int	n;
	int	left;
	int	right;

	n = 0;
	left = 1;
	right = 1;
	while (left + right)
	{
		if ((*phil)->n % 2)
		{
			if (left)
			{
				pthread_mutex_lock(&(*phil)->left->lock);
				if ((*phil)->left->free)
				{
					(*phil)->left->free = 0;
					left = 0;
				}
				pthread_mutex_unlock(&(*phil)->left->lock);
			}
			if (!left)
			{
				pthread_mutex_lock(&(*phil)->right->lock);
				n++;
				if ((*phil)->right->free)
				{
					(*phil)->right->free = 0;
					right = 0;
				}
				pthread_mutex_unlock(&(*phil)->right->lock);
			}
			if (500 < n)
			{
				pthread_mutex_lock(&(*phil)->left->lock);
				(*phil)->left->free = 1;
				pthread_mutex_unlock(&(*phil)->left->lock);
				left = 1;
			}
		}
		else
		{
			if (right)
			{
				pthread_mutex_lock(&(*phil)->right->lock);
				if ((*phil)->right->free)
				{
					(*phil)->right->free = 0;
					right = 0;
				}
				pthread_mutex_unlock(&(*phil)->right->lock);
			}
			if (!right)
			{
				pthread_mutex_lock(&(*phil)->left->lock);
				n++;
				if ((*phil)->left->free)
				{
					(*phil)->left->free = 0;
					left = 0;
				}
				pthread_mutex_unlock(&(*phil)->left->lock);
			}
			if (1500 < n)
			{
				pthread_mutex_lock(&(*phil)->right->lock);
				(*phil)->right->free = 1;
				pthread_mutex_unlock(&(*phil)->right->lock);
				right = 1;
			}
		}
	}
	print(phil, "eat");
	usleep(500000);
	pthread_mutex_lock(&(*phil)->left->lock);
	(*phil)->left->free = 1;
	pthread_mutex_unlock(&(*phil)->left->lock);
	pthread_mutex_lock(&(*phil)->right->lock);
	(*phil)->right->free = 1;
	pthread_mutex_unlock(&(*phil)->right->lock);
	return ;
}
