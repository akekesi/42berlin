/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:24:45 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 22:19:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_moves(t_llist *head_a, t_llist *head_b, t_moves *moves)
{
	int		i;
	int		len_a;
	int		len_b;
	t_moves	moves_curr;
	t_llist	*tmp;

	i = 0;
	len_a = llist_len(head_a);
	len_b = llist_len(head_b);
	set_moves(moves, len_a, len_b);
	tmp = head_a;
	while (1)
	{
		set_moves(
			&moves_curr, opt_move(i, len_a),
			opt_move(llist_pos(head_b, tmp->n), len_b)
			);
		if ((moves_curr.sum) < (moves->sum))
			set_moves(moves, moves_curr.a, moves_curr.b);
		tmp = tmp->next;
		if (head_a == tmp)
			break ;
		i++;
	}
}

void	set_moves(t_moves *moves, int a, int b)
{
	if (a * b < 1)
	{
		moves->a = a;
		moves->b = b;
		moves->ab = 0;
	}
	else
	{
		if (ft_abs(a) < ft_abs(b))
		{
			moves->a = 0;
			moves->b = b - a;
			moves->ab = a;
		}
		else
		{
			moves->a = a - b;
			moves->b = 0;
			moves->ab = b;
		}
	}
	moves->sum = ft_abs(moves->a) + ft_abs(moves->b) + ft_abs(moves->ab);
}

int	opt_move(int move, int len)
{
	if (len - move < move)
		return (move - len);
	return (move);
}
