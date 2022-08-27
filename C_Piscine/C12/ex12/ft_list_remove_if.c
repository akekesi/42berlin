/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:35:27 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/27 13:35:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*elem;
	t_list	*elem_previous;
	t_list	*elem_free;

	elem = *begin_list;
	elem_previous = NULL;
	while (elem)
	{
		if (!cmp(elem->data, data_ref))
		{
			elem_free = elem;
			if (!elem_previous)
				*begin_list = elem->next;
			else
				elem_previous->next = elem->next;
			elem = elem->next;
			free_fct(elem_free);
		}
		else
		{
			elem_previous = elem;
			elem = elem->next;
		}
	}
}
