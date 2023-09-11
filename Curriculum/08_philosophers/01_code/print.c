/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 02:37:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil **phil, long long time, char *message)
{
	static int	do_print = 1;

	pthread_mutex_lock(&(*phil)->info->lock);
	if (do_print)
		printf(
			"%lli %d %s\n",
			time / 1000, (*phil)->id, message);
	if (message[0] == 'd')
		do_print = 0;
	pthread_mutex_unlock(&(*phil)->info->lock);
}
