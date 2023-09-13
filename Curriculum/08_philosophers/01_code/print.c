/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/13 20:29:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil **phil, char *message)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	if ((*phil)->info->print)
		printf(
			"%d %d %s\n",
			get_time_elapsed((*phil)->time_start),
			(*phil)->id,
			message);
	if (message[0] == 'd')
		(*phil)->info->print = 0;
	pthread_mutex_unlock(&(*phil)->info->lock);
}
