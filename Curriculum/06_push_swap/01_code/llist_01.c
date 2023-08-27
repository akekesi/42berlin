/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:03:42 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 14:53:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	llist_add(t_llist **head, t_llist *node)
{
	if (!*head)
		*head = node;
	else
	{
		node->prev = (*head)->prev;
		node->next = *head;
		((*head)->prev)->next = node;
		(*head)->prev = node;
	}
}

void	llist_rot(t_llist **head, int direction)
{
	while (direction > 0)
	{
		*head = (*head)->next;
		direction--;
	}
	while (direction < 0)
	{
		*head = (*head)->prev;
		direction++;
	}
}

t_llist	*llist_del(t_llist **head)
{
	t_llist	*node;

	node = (*head)->prev;
	if (*head == (*head)->next)
		*head = NULL;
	else
	{
		(((*head)->prev)->prev)->next = *head;
		(*head)->prev = ((*head)->prev)->prev;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

void	llist_push(t_llist **head_a, t_llist **head_b)
{
	t_llist	*node;

	if (!*head_b)
		return ;
	llist_rot(head_b, 1);
	node = llist_del(head_b);
	llist_add(head_a, node);
	llist_rot(head_a, -1);
}

void	llist_swap(t_llist **head)
{
	t_llist	*node;

	if (!*head || *head == (*head)->next)
		return ;
	llist_rot(head, 1);
	node = llist_del(head);
	llist_rot(head, 1);
	llist_add(head, node);
	llist_rot(head, -2);
}
