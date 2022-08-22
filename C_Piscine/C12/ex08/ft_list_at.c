/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:28:44 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/16 21:28:44 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int		i;
	t_list	*elem_nbr;

	i = 0;
	elem_nbr = begin_list;
	while (nbr - i && elem_nbr)
	{
		elem_nbr = elem_nbr->next;
		i++;
	}
	return (elem_nbr);
}
