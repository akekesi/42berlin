/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:37:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 20:13:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_llist **head_a, t_llist **head_b)
{
	t_moves	moves;

	llist_push(head_b, head_a);
	llist_push(head_b, head_a);
	while (llist_len(*head_a) > 0)
	{
		get_moves(*head_a, *head_b, &moves);
		do_moves(head_a, head_b, &moves);
	}
	set_moves(
		&moves,
		0,
		opt_move(llist_max_pos(*head_b), llist_len(*head_b))
		);
	do_moves(head_a, head_b, &moves);
	while (llist_len(*head_b) > 0)
	{
		pa(head_a, head_b);
	}
}
