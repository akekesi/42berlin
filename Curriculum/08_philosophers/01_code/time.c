/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/13 21:43:46 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_time_current(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_time_elapsed(int time)
{
	return (get_time_current() - time);
}

int	eat_time(t_phil **phil, int time)
{
	int	time_start;

	time_start = get_time_current();
	if ((*phil)->time_rest < time)
		time = (*phil)->time_rest;
	while (get_time_elapsed(time_start) < time)
	{
		if (is_death(phil))
			return (0);
		usleep(100);
	}
	(*phil)->time_rest -= time;
	if ((*phil)->time_rest <= 0)
	{
		do_die(phil);
		return (0);
	}
	return (1);
}
