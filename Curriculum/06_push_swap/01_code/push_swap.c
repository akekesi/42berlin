/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 22:12:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_llist	*head_a;
	t_llist	*head_b;
	t_llist	*node;

	head_a = NULL;
	head_b = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_putstr("!!!CHECK INPUT!!!\n");
			node = llist_create(ft_atoi(argv[i]));
			if (!llist_is_unique(head_a, node->n))
			{
				llist_free(&head_a);
				llist_free(&head_b);
				llist_free(&node);
				ft_putstr("Error\n");
				return (0);
			}
			llist_add(&head_a, node);
			i++;
		}
		if (llist_is_sorted(head_a))
		{
			llist_free(&head_a);
			return (0);
		}
		print_ab(head_a, head_b);
		if (argc == 3)
		{
			sa(&head_a);
		}
		if (argc == 4)
		{
			sort_3(&head_a);
		}
		if (argc > 4)
		{
			sort(&head_a, &head_b);
		}
		print_ab(head_a, head_b);
	}
	llist_free(&head_a);
	llist_free(&head_b);
}
