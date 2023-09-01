/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 23:03:46 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_llist	*head_a;
	t_llist	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (!fill_a(argc, argv, &head_a))
		return ;
	if (llist_is_sorted(head_a))
	{
		llist_free(&head_a);
		return ;
	}
	if (argc == 3)
		sa(&head_a);
	if (argc == 4)
		sort_3(&head_a);
	if (argc > 4)
		sort(&head_a, &head_b);
	llist_free(&head_a);
	llist_free(&head_b);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		if (!check_pre(argv[1]))
			ft_putstr("Error\n");
	if (argc > 2)
		push_swap(argc, argv);
}
