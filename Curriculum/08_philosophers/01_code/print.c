/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 16:28:48 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil **phil, char *message)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	printf("%d %d %s\n", get_time((*phil)->info->time_0), (*phil)->n, message);
	pthread_mutex_unlock(&(*phil)->info->lock);
}
