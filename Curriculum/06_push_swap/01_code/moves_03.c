/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:56:15 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 18:08:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_llist **head_a)
{
	llist_rrot(head_a);
	ft_putstr("rra\n");
}

void	rrb(t_llist **head_b)
{
	llist_rrot(head_b);
	ft_putstr("rrb\n");
}

void	rrr(t_llist **head_a, t_llist **head_b)
{
	llist_rrot(head_a);
	llist_rrot(head_b);
	ft_putstr("rrr\n");
}
