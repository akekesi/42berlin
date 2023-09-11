/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 04:14:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	get_time_current(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

long long	get_time_elapsed(long long time_0)
{
	return (get_time_current() - time_0);
}

int	eat_time(t_phil **phil, long long time)
{
	long long	time_0;

	if ((*phil)->time_rest < time)
		time = (*phil)->time_rest;
	time_0 = get_time_current();
	while (get_time_elapsed(time_0) <= time)
		if (is_death(phil))
			return (0);
	(*phil)->time_rest -= get_time_elapsed(time_0);
	if ((*phil)->time_rest < 0)
	{
		do_die(phil);
		return (0);
	}
	return (1);
}
