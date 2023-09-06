/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:17 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 19:39:20 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_info(t_info **info, int n)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return ;
	(*info)->n = n;
	pthread_mutex_init(&((*info)->print), NULL);
}

void	free_info(t_info **info)
{
	free(*info);
}
