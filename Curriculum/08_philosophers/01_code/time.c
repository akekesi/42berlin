/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 16:28:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_time(int time_0)
{
	struct timeval	time_1;

	gettimeofday(&time_1, NULL);
	return (time_1.tv_sec * 1000 + time_1.tv_usec / 1000 - time_0);
}

int	set_time(t_phil **phil, int time_0)
{
	struct timeval	time;
	int				time_1;

	time_1 = get_time(time_0);
	if (10 < time_1)
	{
		(*phil)->time_rest -= time_1;
		if (is_death(phil))
			return (-1);
		if ((*phil)->time_rest < time_1)
		{
			(*phil)->time_rest = 0;
			do_die(phil);
			return (-1);
		}
		gettimeofday(&time, NULL);
		time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
	}
	return (time_0);
}

void	do_usleep(t_phil **phil, int time)
{
	int	i;
	int	delta;

	if ((*phil)->time_rest < time)
	{
		do_die(phil);
		return ;
	}
	i = 0;
	delta = 10;
	usleep((time % delta) * 1000);
	while (i * delta < time)
	{
		if (is_death(phil))
		{
			(*phil)->time_rest -= i * delta;
			return ;
		}
		usleep(delta * 1000);
		i++;
	}
	(*phil)->time_rest -= time;
}
