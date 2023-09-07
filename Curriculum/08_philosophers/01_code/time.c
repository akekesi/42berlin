/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 23:10:06 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_time(int time_0)
{
	struct timeval	time_1;

	gettimeofday(&time_1, NULL);
	return (time_1.tv_sec * 1000 + time_1.tv_usec / 1000 - time_0);
}

void	do_usleep(t_phil **phil, int time)
{
	int	i;
	int	delta;

	if ((*phil)->time_rest < time)
	{
		pthread_mutex_lock(&(*phil)->info->lock);
		(*phil)->info->die = 1;
		pthread_mutex_unlock(&(*phil)->info->lock);
		print(phil, "died");
		(*phil)->time_rest = 0;
		return ;
	}
	i = 0;
	delta = 10;
	usleep((time % delta) * 1000);
	while (i * delta < time)
	{
		if (check_die(phil))
		{
			(*phil)->time_rest -= i * delta;
			return ;
		}
		usleep(delta * 1000);
		i++;
	}
	(*phil)->time_rest -= time;
}

void	set_time(t_phil **phil)
{
	return ;
}
