/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:00 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/13 17:13:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;
	t_list	*elem_previous;

	if (size == 0)
		return (NULL);
	elem = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		elem_previous = ft_create_elem(strs[i]);
		elem_previous -> next = elem;
		elem = elem_previous;
		i++;
	}
	return (elem);
}
