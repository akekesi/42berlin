/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:59:02 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 06:07:47 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	int		i;
	t_phil	*phil;

	phil = (t_phil *)arg;
	i = 0;
	while (0 < phil->time_sync - get_time_current())
		usleep(1);
	while (i < phil->n_eat || phil->n_eat == -1)
	{
		if (is_death(&phil))
			break ;
		do_think(&phil);
		do_eat(&phil);
		if (is_death(&phil))
			break ;
		do_sleep(&phil);
		eat_time(&phil, 100);
		i++;
	}
	return (NULL);
}
