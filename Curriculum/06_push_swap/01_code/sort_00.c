/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:37:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 20:40:18 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_llist **head_a, t_llist **head_b)
{
	t_moves	moves;

	pb(head_a, head_b);
	pb(head_a, head_b);
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

/*
1 2 3 <------------------------------OK
1 3 2 --sa--> 3 1 2 --ra--> 1 2 3 <--OK
              3 1 2 --ra--> 1 2 3 <--OK
2 1 3 --sa--> 1 2 3 <----------------OK
3 2 1 --sa--> 2 3 1 --rra-> 1 2 3 <--OK
              2 3 1 --rra-> 1 2 3 <--OK
*/
void	sort_3(t_llist **head)
{
	int	min_pos;
	int	max_pos;

	min_pos = llist_min_pos(*head);
	max_pos = llist_max_pos(*head);
	if ((min_pos + 1) % 3 == max_pos)
		sa(head);
	max_pos = llist_max_pos(*head);
	if (max_pos == 0)
		ra(head);
	if (max_pos == 1)
		rra(head);
}
