/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:03:42 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/18 19:59:54 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	llist_rot(t_llist **head)
{
	if (!*head)
		return ;
	*head = (*head)->next;
}

void	llist_rrot(t_llist **head)
{
	if (!*head)
		return ;
	*head = (*head)->prev;
}

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
		str = tmp->line;
		tmp = tmp->next;
		ft_putstr(str);
		if (head == tmp)
			return ;
	}
}
