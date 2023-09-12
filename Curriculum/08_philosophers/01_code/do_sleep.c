/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:09:30 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 22:41:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	do_sleep(t_phil **phil)
{
	print(phil, "is sleeping");
	if (!eat_time(phil, (*phil)->time_sleep))
		return (0);
	return (1);
}
