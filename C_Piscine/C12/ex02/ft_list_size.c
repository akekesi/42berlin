/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:45:03 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 23:45:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*p;

	if (!begin_list)
		return (0);
	i = 1;
	p = begin_list;
	while (p -> next)
	{
		p = p -> next;
		i++;
	}
	return (i);
}
