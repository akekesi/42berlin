/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:53:41 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 23:03:17 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_die(t_phil **phil)
{
	pthread_mutex_lock(&(*phil)->info->lock);
	if (!(*phil)->info->death)
		(*phil)->info->death = 1;
	pthread_mutex_unlock(&(*phil)->info->lock);
	print(phil, "died");
	(*phil)->time_rest = 0; // this is not important, just for blackbox :)
}

int	is_death(t_phil **phil)
{
	int	die;

	die = 0;
	pthread_mutex_lock(&(*phil)->info->lock);
	if ((*phil)->info->death)
		die = 1;
	pthread_mutex_unlock(&(*phil)->info->lock);
	return (die);
}
