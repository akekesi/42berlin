/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:17 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/07 23:08:22 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_info(t_info **info, int n)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return ;
	(*info)->n = n;
	(*info)->die = 0;
	(*info)->time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_init(&((*info)->lock), NULL);
}

void	free_info(t_info **info)
{
	free(*info);
}
