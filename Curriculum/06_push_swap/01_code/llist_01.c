/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:03:42 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 17:24:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	llist_rot(t_llist **head)
{
	*head = (*head)->next;
}

void	llist_rrot(t_llist **head)
{
	*head = (*head)->prev;
}

void	llist_push(t_llist **head_a, t_llist **head_b)
{
	t_llist	*node;

	if (!*head_b)
		return ;
	llist_rot(head_b);
	node = llist_del(head_b);
	llist_add(head_a, node);
	llist_rrot(head_a);
}

void	llist_swap(t_llist **head)
{
	t_llist	*node;

	if (!*head || *head == (*head)->next)
		return ;
	llist_rot(head);
	node = llist_del(head);
	llist_rot(head);
	llist_add(head, node);
	llist_rrot(head);
	llist_rrot(head);
}
