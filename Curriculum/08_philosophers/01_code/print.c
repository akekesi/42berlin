/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 23:05:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil **phil, char *message)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	if ((*phil)->info->print)
		printf(
			"%lli %d %s\n",
			(get_time_current() - (*phil)->time_start) / 1000,
			(*phil)->id,
			message);
	if (message[0] == 'd')
		(*phil)->info->print = 0;
	pthread_mutex_unlock(&(*phil)->info->lock);
}
