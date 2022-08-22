/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:23:35 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/22 21:23:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(
	t_list *begin_list,
	void (*f)(void *),
	void *data_ref,
	int (*cmp)()
)
{
	t_list	*elem;

	elem = begin_list;
	while (elem)
	{
		if (!cmp(elem->data, data_ref))
			f(elem->data);
		elem = elem->next;
	}
}
