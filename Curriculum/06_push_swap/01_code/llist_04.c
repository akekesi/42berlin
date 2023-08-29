/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:53:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 22:10:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	llist_is_sorted(t_llist *head)
{
	int		n;
	t_llist	*tmp;

	tmp = head;
	n = tmp->n;
	while (tmp)
	{
		tmp = tmp->next;
		if (head == tmp)
			break ;
		if (n > tmp->n)
			return (0);
		n = tmp->n;
	}
	return (1);
}

int	llist_is_unique(t_llist *head, int n)
{
	t_llist	*tmp;

	tmp = head;
	while (tmp)
	{
		if (n == tmp->n)
			return (0);
		tmp = tmp->next;
		if (head == tmp)
			break ;
	}
	return (1);
}
