/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:59:02 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 03:02:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	int		i;
	t_phil	*phil;

	phil = (t_phil *)arg;
	i = 0;
	while ((i < phil->n_eat || phil->n_eat == -1) && !is_death(&phil))
	{
		do_think(&phil);
		do_eat(&phil);
		do_sleep(&phil);
		usleep(100);
		i++;
	}
	return (NULL);
}
