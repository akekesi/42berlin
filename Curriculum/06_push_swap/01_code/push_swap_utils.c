/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:27:41 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/01 17:38:19 by akekesi          ###   ########.fr       */
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

void	execute_rule(t_llist **head_a, t_llist **head_b, char *rule)
{
	if (rule[0] == 's')
		execute_rule_sub_s(head_a, head_b, rule);
	if (rule[0] == 'p')
		execute_rule_sub_p(head_a, head_b, rule);
	if (rule[0] == 'r')
		execute_rule_sub_r(head_a, head_b, rule);
}

void	execute_rule_sub_s(t_llist **head_a, t_llist **head_b, char *rule)
{
	if (!ft_strcmp(rule, "sa\n"))
		llist_swap(head_a);
	if (!ft_strcmp(rule, "sb\n"))
		llist_swap(head_b);
	if (!ft_strcmp(rule, "ss\n"))
	{
		llist_swap(head_a);
		llist_swap(head_b);
	}
}

void	execute_rule_sub_p(t_llist **head_a, t_llist **head_b, char *rule)
{
	if (!ft_strcmp(rule, "pa\n"))
		llist_push(head_a, head_b);
	if (!ft_strcmp(rule, "pb\n"))
		llist_push(head_b, head_a);
}

void	execute_rule_sub_r(t_llist **head_a, t_llist **head_b, char *rule)
{
	if (!ft_strcmp(rule, "ra\n"))
		llist_rot(head_a);
	if (!ft_strcmp(rule, "rb\n"))
		llist_rot(head_b);
	if (!ft_strcmp(rule, "rr\n"))
	{
		llist_rot(head_a);
		llist_rot(head_b);
	}
	if (!ft_strcmp(rule, "rra\n"))
		llist_rrot(head_a);
	if (!ft_strcmp(rule, "rrb\n"))
		llist_rrot(head_b);
	if (!ft_strcmp(rule, "rrr\n"))
	{
		llist_rrot(head_a);
		llist_rrot(head_b);
	}
}
