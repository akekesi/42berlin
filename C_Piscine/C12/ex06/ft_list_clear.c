/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:52:01 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/16 13:52:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem_free;

	while (begin_list)
	{
		elem_free = begin_list;
		begin_list = begin_list->next;
		free_fct(elem_free->data);
		free(elem_free);
	}
}
