/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:55:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 17:47:26 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	llist_len(t_llist *head)
{
	int		i;
	t_llist	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
		if (head == tmp)
			break ;
	}
	return (i);
}

int	llist_pos(t_llist *head, int n)
{
	int	pos;

	pos = llist_minmax_pos(head, n);
	if (pos < 0)
		pos = llist_max_pos(head);
	return (pos);
}

int	llist_max_pos(t_llist *head)
{
	int		i;
	int		max;
	int		pos;
	t_llist	*tmp;

	pos = -1;
	if (!head)
		return (pos);
	i = 0;
	tmp = head;
	max = -2147483647 - 1;
	while (1)
	{
		if (max < tmp->n)
		{
			max = tmp->n;
			pos = i;
		}
		tmp = tmp->next;
		if (head == tmp)
			break ;
		i++;
	}
	return (pos);
}

int	llist_minmax_pos(t_llist *head, int n)
{
	int		i;
	int		minmax;
	int		pos;
	t_llist	*tmp;

	pos = -1;
	if (!head)
		return (pos);
	i = 0;
	tmp = head;
	minmax = -2147483647 - 1;
	while (1)
	{
		if (minmax < tmp->n && tmp->n < n)
		{
			minmax = tmp->n;
			pos = i;
		}
		tmp = tmp->next;
		if (head == tmp)
			break ;
		i++;
	}
	return (pos);
}
