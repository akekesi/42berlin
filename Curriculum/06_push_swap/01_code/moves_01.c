/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:56:15 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 18:20:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_llist **head_a)
{
	llist_swap(head_a);
	ft_putstr("sa\n");
}

void	sb(t_llist **head_b)
{
	llist_swap(head_b);
	ft_putstr("sb\n");
}

void	ss(t_llist **head_a, t_llist **head_b)
{
	llist_swap(head_a);
	llist_swap(head_b);
	ft_putstr("ss\n");
}

void	pa(t_llist **head_a, t_llist **head_b)
{
	llist_push(head_a, head_b);
	ft_putstr("pa\n");
}

void	pb(t_llist **head_a, t_llist **head_b)
{
	llist_push(head_b, head_a);
	ft_putstr("pb\n");
}
