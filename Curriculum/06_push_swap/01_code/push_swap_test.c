/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:39:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 20:48:56 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ab(t_llist *head_a, t_llist *head_b)
{
	ft_putstr("stack-a:\n");
	llist_print(head_a);
	ft_putstr("stack-b:\n");
	llist_print(head_b);
}

void	print_len(t_llist *head)
{
	char	*len;

	len = ft_itoa(llist_len(head));
	ft_putstr(len);
	free(len);
}

void	print_pos(t_llist *head, int n)
{
	char	*max_pos;

	max_pos = ft_itoa(llist_pos(head, n));
	ft_putstr(max_pos);
	free(max_pos);
}

void	print_moves(t_moves moves)
{
	char	*str;

	ft_putstr("moves:\n");
	ft_putstr("a:   ");
	str = ft_itoa(moves.a);
	ft_putstr(str);
	free(str);
	ft_putstr("\n");
	ft_putstr("b:   ");
	str = ft_itoa(moves.b);
	ft_putstr(str);
	free(str);
	ft_putstr("\n");
	ft_putstr("ab:  ");
	str = ft_itoa(moves.ab);
	ft_putstr(str);
	free(str);
	ft_putstr("\n");
	ft_putstr("sum: ");
	str = ft_itoa(moves.sum);
	ft_putstr(str);
	free(str);
	ft_putstr("\n");
}
