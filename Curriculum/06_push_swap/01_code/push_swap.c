/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/29 20:18:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
- check input
- check sort
- argc < 3
- argc = 3
- argc > 3
*/
int	main(int argc, char **argv)
{
	int		i;
	t_llist	*head_a;
	t_llist	*head_b;
	t_llist	*node;

	head_a = NULL;
	head_b = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			node = llist_create(ft_atoi(argv[i]));
			llist_add(&head_a, node);
			i++;
		}
		if (argc < 3)
		{
			ft_putstr("SORT LEN = 2\n");
		}
		if (argc < 4)
		{
			ft_putstr("SORT LEN = 3\n");
		}
		if (argc > 4)
		{
			print_ab(head_a, head_b);
			sort(&head_a, &head_b);
			print_ab(head_a, head_b);
		}
	}
	llist_free(&head_a);
	llist_free(&head_b);
}
