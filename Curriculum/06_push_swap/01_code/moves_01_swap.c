/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_01_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:56:15 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 21:34:01 by akekesi          ###   ########.fr       */
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
