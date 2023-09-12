/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:17 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 20:52:30 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_info(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return ;
	(*info)->print = 1;
	(*info)->death = 0;
	pthread_mutex_init(&((*info)->lock), NULL);
}

void	free_info(t_info **info)
{
	free(*info);
}
