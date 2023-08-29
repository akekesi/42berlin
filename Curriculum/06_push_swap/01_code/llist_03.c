/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:23:21 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 19:56:40 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	llist_print(t_llist *head)
{
	char	*str;
	t_llist	*tmp;

	if (!head)
	{
		ft_putstr("head is empty\n");
		return ;
	}
	tmp = head;
	while (1)
	{
		str = ft_itoa(tmp->n);
		tmp = tmp->next;
		ft_putstr(str);
		ft_putstr("\n");
		free(str);
		if (head == tmp)
			return ;
	}
}
