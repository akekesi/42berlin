/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_00_get_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:24:45 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 21:36:22 by akekesi          ###   ########.fr       */
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
			&moves_curr,
			opt_move(i, len_a),
			opt_move(llist_pos(head_b, tmp->n), len_b)
			);
		if ((moves_curr.sum) < (moves->sum))
			cpy_moves(moves, &moves_curr);
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

void	cpy_moves(t_moves *moves_dst, t_moves *moves_src)
{
	moves_dst->a = moves_src->a;
	moves_dst->b = moves_src->b;
	moves_dst->ab = moves_src->ab;
	moves_dst->sum = moves_src->sum;
}

int	opt_move(int move, int len)
{
	if (len - move < move)
		return (move - len);
	return (move);
}
