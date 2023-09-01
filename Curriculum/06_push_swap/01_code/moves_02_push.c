/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_02_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:56:15 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 21:33:51 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
