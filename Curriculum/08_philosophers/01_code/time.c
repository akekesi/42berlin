/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 00:20:44 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_time_current(void)
{
	struct timeval	time_1;

	gettimeofday(&time_1, NULL);
	return (time_1.tv_sec * 1000 + time_1.tv_usec / 1000);
}

int	get_time_elapsed(int time_0)
{
	return (get_time_current() - time_0);
}

int	set_time(t_phil **phil, int time_0)
{
	int				time_1;

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

void	do_usleep(t_phil **phil, int time)
{
	int	time_current;

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
