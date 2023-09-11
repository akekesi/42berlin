/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:09:30 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/11 02:16:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_sleep(t_phil **phil)
{
	print(phil, get_time_elapsed((*phil)->info->time_0), "is sleeping");
	eat_time(phil, (*phil)->time_sleep);
}
