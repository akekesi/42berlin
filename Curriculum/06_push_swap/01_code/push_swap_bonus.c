/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:27:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/02 23:46:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"

void	push_swap_checker(int argc, char **argv)
{
	char	*rule;
	t_llist	*head_a;
	t_llist	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (!fill_a(argc, argv, &head_a))
		return ;
	while (1)
	{
		rule = get_next_line(0);
		if (!rule)
			break ;
		if (!check_rule_extra(&head_a, &head_b, rule))
			return ;
		execute_rule(&head_a, &head_b, rule);
		free(rule);
	}
	if (llist_is_sorted(head_a) && !head_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	llist_free(&head_a);
	llist_free(&head_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap_checker(argc, argv);
}
