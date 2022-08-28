/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:51:02 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/28 10:51:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*elem_last;

	elem_last = *begin_list1;
	if (!elem_last)
		*begin_list1 = begin_list2;
	else
	{
		while (elem_last->next)
			elem_last = elem_last->next;
		elem_last->next = begin_list2;
	}
}
