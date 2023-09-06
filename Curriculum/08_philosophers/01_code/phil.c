/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:03:14 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 20:03:15 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_phils_sub1(t_phil **phils, int argc, char **argv)
{
	int	i;
	int	n;

	n = ft_atoi(argv[1]);
	*phils = (t_phil *)malloc(sizeof(t_phil) * n);
	if (!(*phils))
		return ;
	i = 0;
	while (i < n)
	{
		(*phils)[i].n = i;
		(*phils)[i].time_die = ft_atoi(argv[2]);
		(*phils)[i].time_eat = ft_atoi(argv[3]);
		(*phils)[i].time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			(*phils)[i].n_eat = ft_atoi(argv[5]);
		if (argc == 5)
			(*phils)[i].n_eat = -1;
		i++;
	}
}

void	make_phils_sub2(t_phil **phils, t_info **info, t_fork **forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		(*phils)[i].left = &((*forks)[i]);
		(*phils)[i].right = &((*forks)[(i + 1) % n]);
		(*phils)[i].info = *info;
		i++;
	}
}

void	free_phils(t_phil **phils)
{
	free(*phils);
}
