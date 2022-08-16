/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:02:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/13 10:02:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*p;

	if (!begin_list)
		return (NULL);
	p = begin_list;
	while (p->next)
		p = p->next;
	return (p);
}
