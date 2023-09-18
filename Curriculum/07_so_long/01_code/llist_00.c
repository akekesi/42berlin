/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:55:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/18 21:53:10 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_llist	*llist_create(char *line)
{
	t_llist	*node;

	node = (t_llist *)malloc(sizeof(t_llist));
	if (!node)
		return (NULL);
	node->line = line;
	node->prev = node;
	node->next = node;
	return (node);
}

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
		free(tmp->line);
		free(tmp);
	}
}
