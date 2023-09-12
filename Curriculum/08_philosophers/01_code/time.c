/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 23:05:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	get_time_current(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	eat_time(t_phil **phil, long long time)
{
	long long	time_start;
	long long	time_delta;

	// increase precision with this: 
	// int p = 1;
	// if (time > 1000)
	// 	p = 1000;
	if ((*phil)->time_rest < time)
		time = (*phil)->time_rest;
	time_start = get_time_current();
	time_delta = get_time_current() - time_start;
	while (time_delta < time)
	{
		if (is_death(phil))
			return (0);
		usleep(1); // this needed for 20 401 200 200 no to die
		time_delta = get_time_current() - time_start;
	}
	(*phil)->time_rest -= time;
	if ((*phil)->time_rest <= 0)
	{
		do_die(phil);
		return (0);
	}
	return (1);
}

// 900.000 - 800.000 < 100.000
// 900.120 - 800.123 < 100.000
