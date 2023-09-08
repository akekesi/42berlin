/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:09:30 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/08 16:36:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_sleep(t_phil **phil)
{
	if (is_death(phil))
		return ;
	print(phil, "is sleeping");
	do_usleep(phil, (*phil)->time_sleep);
}
