/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 18:57:17 by akekesi          ###   ########.fr       */
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
	pthread_mutex_lock(&(*phil)->info->print);
	printf("%lld %d %s\n", get_time((*phil)->info->time_0), (*phil)->n, message);
	pthread_mutex_unlock(&(*phil)->info->print);
	return ;
}

long long	get_time(long long time_0)
{
	struct timeval	time_1;

	gettimeofday(&time_1, NULL);
	return (time_1.tv_sec * 1000 + time_1.tv_usec / 1000 - time_0);
}
