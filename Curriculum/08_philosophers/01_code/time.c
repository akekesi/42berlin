/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 03:01:13 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	get_time_current(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	get_time_elapsed(long long time_0)
{
	return (get_time_current() - time_0);
}

long long	set_time(t_phil **phil, long long time_0)
{
	long long	time_1;

	if (is_death(phil))
		return (-1);
	time_1 = get_time_elapsed(time_0);
	if (1 < time_1)
	{
		if ((*phil)->time_rest < time_1)
		{
			(*phil)->time_rest = 0;
			do_die(phil);
			return (-1);
		}
		(*phil)->time_rest -= time_1;
		time_0 = get_time_current();
	}
	return (time_0);
}

void	do_usleep(t_phil **phil, long long time)
{
	long long	time_current;

	time_current = get_time_current();
	while (get_time_elapsed(time_current) < time)
	{
		if (is_death(phil))
			return ;
		if ((*phil)->time_rest <= get_time_elapsed(time_current))
		{
			do_die(phil);
			return ;
		}
		usleep(10);
	}
	(*phil)->time_rest -= time;
}
