/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/30 22:14:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_a(int argc, char **argv, t_llist **head_a)
{
	int		i;
	t_llist	*node;

	i = 1;
	while (i < argc)
	{
		if (!check_pre(argv[i]))
		{
			llist_free(head_a);
			ft_putstr("Error\n");
			return (0);
		}
		node = llist_create(ft_atoi(argv[i]));
		if (!llist_is_unique(*head_a, node->n))
		{
			llist_free(head_a);
			llist_free(&node);
			ft_putstr("Error\n");
			return (0);
		}
		llist_add(head_a, node);
		i++;
	}
	return (1);
}

void	push_swap_sub(int argc, char **argv)
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
	print_ab(head_a, head_b);
	if (argc == 3)
		sa(&head_a);
	if (argc == 4)
		sort_3(&head_a);
	if (argc > 4)
		sort(&head_a, &head_b);
	print_ab(head_a, head_b);
	llist_free(&head_a);
	llist_free(&head_b);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		if (!check_pre(argv[1]))
			ft_putstr("Error\n");
	if (argc > 2)
		push_swap_sub(argc, argv);
}
