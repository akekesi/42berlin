/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:56:15 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 18:08:24 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_llist **head_a)
{
	llist_rot(head_a);
	ft_putstr("ra\n");
}

void	rb(t_llist **head_b)
{
	llist_rot(head_b);
	ft_putstr("rb\n");
}

void	rr(t_llist **head_a, t_llist **head_b)
{
	llist_rot(head_a);
	llist_rot(head_b);
	ft_putstr("rr\n");
}
