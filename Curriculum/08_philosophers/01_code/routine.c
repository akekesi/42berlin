/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:59:02 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 03:39:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	int		i;
	t_phil	*phil;

	phil = (t_phil *)arg;
	i = 0;
	while (i < phil->n_eat || phil->n_eat == -1)
	{
		if (is_death(&phil))
			break ;
		do_think(&phil);
		printf("-%d->%lli\n", phil->id, get_time_elapsed(phil->info->time_0));
		do_eat(&phil);
		if (is_death(&phil))
			break ;
		do_sleep(&phil);
		eat_time(&phil, 100);
		printf("-%d->%lli\n", phil->id, get_time_elapsed(phil->info->time_0));
		i++;
	}
	return (NULL);
}
