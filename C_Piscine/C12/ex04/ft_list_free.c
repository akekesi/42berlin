/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:00:29 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/13 12:00:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_free(t_list **begin_list)
{
	t_list	*p;
	t_list	*p_next;

	p = *begin_list;
	while (p)
	{
		p_next = p -> next;
		free(p -> data);
		free(p);
		p = p_next;
	}
	*begin_list = NULL;
}
