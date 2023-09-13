/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:59:02 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/13 21:43:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
usleep(200) needed for od number of philosophers
*/
void	*routine(void *arg)
{
	int		i;
	t_phil	*phil;

	phil = (t_phil *)arg;
	i = 0;
	while (0 < phil->time_start - get_time_current())
		usleep(100);
	while (i < phil->n_eat || phil->n_eat == -1)
	{
		do_think(&phil);
		if (!do_eat(&phil))
			break ;
		if (!do_sleep(&phil))
			break ;
		usleep(200);
		i++;
	}
	return (NULL);
}
