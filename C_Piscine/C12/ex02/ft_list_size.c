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

int	ft_list_size(t_list *beginn_list)
{
	int		i;
	t_list	*p;

	i = 1;
	p = beginn_list;
	while (p -> next)
	{
		p = p -> next;
		i++;
	}
	return (i);
}
