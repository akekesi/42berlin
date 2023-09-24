/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:03:42 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 20:53:50 by akekesi          ###   ########.fr       */
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

int	llist_len(t_llist *head)
{
	int		i;
	t_llist	*tmp;

	i = 0;
	if (!head)
		return (i);
	tmp = head;
	while (1)
	{
		i++;
		tmp = tmp->next;
		if (head == tmp)
			return (i);
	}
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
		str = tmp->value;
		tmp = tmp->next;
		ft_putstr(str);
		if (head == tmp)
			return ;
	}
}
