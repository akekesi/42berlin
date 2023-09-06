/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 22:44:02 by akekesi          ###   ########.fr       */
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
	printf("%d:  %s\n", (*phil)->n, message);
	pthread_mutex_unlock(&(*phil)->info->print);
	return ;
}
