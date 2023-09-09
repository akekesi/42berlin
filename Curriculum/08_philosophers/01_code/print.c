/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 03:02:41 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil **phil, char *message)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	printf(
		"%lli %d %s\n",
		get_time_elapsed((*phil)->info->time_0), (*phil)->n + 1, message);
	pthread_mutex_unlock(&(*phil)->info->lock);
}
