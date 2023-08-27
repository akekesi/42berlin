/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 15:53:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
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
			str = ft_itoa(node->n);
			i++;
			free(str);
		}
		ft_putstr("CREATE\n");
		print_ab(head_a, head_b, 1);
		ft_putstr("-------------\n");

		ft_putstr("SWAP-A\n");
		llist_swap(&head_a);
		print_ab(head_a, head_b, 1);
		ft_putstr("-------------\n");

		ft_putstr("PUSH-B\n");
		llist_push(&head_b, &head_a);
		print_ab(head_a, head_b, 1);
		ft_putstr("-------------\n");
	}
	llist_free(&head_a);
	llist_free(&head_b);
}
