/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:59:02 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 15:01:51 by akekesi          ###   ########.fr       */
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
		if (!check_die(&phil))
			do_eat(&phil);
		if (!check_die(&phil))
			do_sleep(&phil);
		if (!check_die(&phil))
			do_think(&phil);
		if (check_die(&phil))
			break ;
		i++;
	}
	return (NULL);
}
