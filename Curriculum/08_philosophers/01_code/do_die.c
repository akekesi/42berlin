/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:53:41 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 00:08:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_die(t_phil **phil)
{
	int	first_death;

	first_death = 1;
	pthread_mutex_lock(&(*phil)->info->lock);
	if (!(*phil)->info->die)
	{
		(*phil)->info->die = 1;
		first_death = 1;
	}
	pthread_mutex_unlock(&(*phil)->info->lock);
	if (first_death)
		print(phil, "died");
	(*phil)->time_rest = 0;
}

int	is_death(t_phil **phil)
{
	int	die;

	die = 0;
	pthread_mutex_lock(&(*phil)->info->lock);
	if ((*phil)->info->die)
		die = 1;
	pthread_mutex_unlock(&(*phil)->info->lock);
	return (die);
}
