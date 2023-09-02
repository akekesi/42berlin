/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:53:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/02 23:46:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digits(char *str)
{
	if ((*str == '-' || *str == '+') && ft_strlen(str) > 1)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	n;
	int	n_new;
	int	i;

	i = 0;
	n = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (214748364 < n)
			return (0);
		n *= 10;
		n_new = str[i] - '0';
		if (str[0] != '-')
			if ((2147483647 - n_new) < n)
				return (0);
		if (str[0] == '-')
			if ((-2147483648 + n_new) > -n)
				return (0);
		n += n_new;
		i++;
	}
	return (1);
}

int	check_pre(char *str)
{
	if (!check_digits(str))
		return (0);
	if (!check_int(str))
		return (0);
	return (1);
}

int	check_rule(char *rule)
{
	if (!ft_strcmp(rule, "sa\n"))
		return (1);
	if (!ft_strcmp(rule, "sb\n"))
		return (1);
	if (!ft_strcmp(rule, "ss\n"))
		return (1);
	if (!ft_strcmp(rule, "pa\n"))
		return (1);
	if (!ft_strcmp(rule, "pb\n"))
		return (1);
	if (!ft_strcmp(rule, "ra\n"))
		return (1);
	if (!ft_strcmp(rule, "rb\n"))
		return (1);
	if (!ft_strcmp(rule, "rr\n"))
		return (1);
	if (!ft_strcmp(rule, "rra\n"))
		return (1);
	if (!ft_strcmp(rule, "rrb\n"))
		return (1);
	if (!ft_strcmp(rule, "rrr\n"))
		return (1);
	return (0);
}

int	check_rule_extra(t_llist **head_a, t_llist **head_b, char *rule)
{
	if (!check_rule(rule))
	{
		ft_putstr("Error\n");
		free(rule);
		llist_free(head_a);
		llist_free(head_b);
		return (0);
	}
	return (1);
}
