/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:01:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 20:02:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_moves(t_llist **head_a, t_llist **head_b, t_moves *moves)
{
	do_moves_sub_a(head_a, moves);
	do_moves_sub_b(head_b, moves);
	do_moves_sub_ab(head_a, head_b, moves);
	pb(head_a, head_b);
}

void	do_moves_sub_a(t_llist **head_a, t_moves *moves)
{
	int	a;
	int	b;
	int	ab;

	a = moves->a;
	b = moves->b;
	ab = moves->ab;
	while (a > 0)
	{
		ra(head_a);
		a--;
	}
	while (a < 0)
	{
		rra(head_a);
		a++;
	}
}

void	do_moves_sub_b(t_llist **head_b, t_moves *moves)
{
	int	a;
	int	b;
	int	ab;

	a = moves->a;
	b = moves->b;
	ab = moves->ab;
	while (b > 0)
	{
		rb(head_b);
		b--;
	}
	while (b < 0)
	{
		rrb(head_b);
		b++;
	}
}

void	do_moves_sub_ab(t_llist **head_a, t_llist **head_b, t_moves *moves)
{
	int	a;
	int	b;
	int	ab;

	a = moves->a;
	b = moves->b;
	ab = moves->ab;
	while (ab > 0)
	{
		rr(head_a, head_b);
		ab--;
	}
	while (ab < 0)
	{
		rrr(head_a, head_b);
		ab++;
	}
}
