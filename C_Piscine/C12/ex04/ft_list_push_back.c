/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:57:35 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/13 09:57:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem_last_old;
	t_list	*elem_last_new;

	elem_last_new = ft_create_elem(data);
	if (*begin_list)
	{
		elem_last_old = ft_list_last(*begin_list);
		elem_last_old->next = elem_last_new;
	}
	else
		*begin_list = elem_last_new;
}
