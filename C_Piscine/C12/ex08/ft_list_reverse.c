/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:11:08 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/17 14:11:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	int		size;
	t_list	*begin_list_new;
	t_list	*elem_previous;
	
	begin_list_new = ft_list_last(*begin_list);
	size = ft_list_size(*begin_list);

	while (0 < --size)
	{
		elem_previous = ft_list_at(*begin_list, (size - 1));
		elem_previous->next->next = elem_previous;
		elem_previous->next = NULL;
	}
	*begin_list = begin_list_new;
}