/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:03:14 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 17:37:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_phils(t_phil **phils, int n, t_fork **forks)
{
	int	i;

	*phils = (t_phil *)malloc(sizeof(t_phil) * n);
	if (!(*phils))
		return ;
	i = 0;
	while (i < n)
	{
		(*phils)[i].n = i;
		(*phils)[i].left = &((*forks)[i]);
		(*phils)[i].right = &((*forks)[(i + 1) % n]);
		i++;
	}
}

void	free_phils(t_phil **phils)
{
	free(*phils);
}
