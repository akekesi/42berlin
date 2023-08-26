/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:55:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/26 23:47:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*llist_create(int n)
{
	t_llist	*node;

	node = (t_llist *)malloc(sizeof(t_llist));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = node;
	node->next = node;
	return (node);
}

void	llist_free(t_llist **head)
{
	t_llist	*tmp;

	if (!*head)
		return ;
	((*head)->prev)->next = NULL;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
