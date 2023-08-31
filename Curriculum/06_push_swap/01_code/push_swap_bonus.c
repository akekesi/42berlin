/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/31 23:26:23 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"
#include <stdio.h> // DELETE THIS!!!


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

void	push_swap_checker(int argc, char **argv)
{
	char	*rule;
	t_llist	*head_a;
	t_llist	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (!fill_a(argc, argv, &head_a))
		return ;
	print_ab(head_a, head_b);
	while (1)
	{
		rule = get_next_line(0);
		printf("-->%s<--\n", rule);
		printf("-->quit: ctrl+d<--\n");
		if (!rule)
		{
			printf("-->break<--");
			break ;
		}
		// free(rule);
	}
	llist_free(&head_a);
	llist_free(&head_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap_checker(argc, argv);
}
