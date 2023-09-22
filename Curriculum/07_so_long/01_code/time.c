/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:09:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/22 19:54:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	eat_time(int time)
{
	int	time_start;

	time_start = get_time_current();
	while (get_time_elapsed(time_start) < time)
	{
		usleep(100);
	}
	return (1);
}
