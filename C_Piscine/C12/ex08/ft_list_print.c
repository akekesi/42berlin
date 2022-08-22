/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:05:36 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/16 22:05:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_print(t_list *being_list)
{
	int		i;
	t_list	*elem_print;

	i = 0;
	if (!being_list)
		printf("elem_%d: %p\n", i, being_list);
	elem_print = being_list;
	while (elem_print)
	{
		printf("elem_%d: %p --> %p\n", i, elem_print, elem_print->next);
		elem_print = elem_print->next;
		i++;
	}
}
