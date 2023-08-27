/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:39:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 15:06:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ab(t_llist *head_a, t_llist *head_b)
{
	ft_putstr("stack a:\n");
	llist_print(head_a);
	ft_putstr("stack b:\n");
	llist_print(head_b);
}
