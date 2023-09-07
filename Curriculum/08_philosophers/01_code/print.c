/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 23:09:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
	???
	first run without write NOK
	one run with write --> OK
	after that, without write OK too
	write(1, "", 0);
	???
*/
void	print(t_phil **phil, char *message)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	printf("%d %d %s\n", get_time((*phil)->info->time_0), (*phil)->n, message);
	// printf("-----> %d\n", (*phil)->time_rest);
	pthread_mutex_unlock(&(*phil)->info->lock);
}
