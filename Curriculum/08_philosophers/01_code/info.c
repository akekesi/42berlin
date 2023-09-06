/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:17 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 18:41:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_info(int argc, char **argv, t_info **info)
{
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return ;
	forks = NULL;
	phils = NULL;
	threads = NULL;
	init_info_sub1(&forks, &phils, &threads, ft_atoi(argv[1]));
	(*info)->n = ft_atoi(argv[1]);
	(*info)->time_die = ft_atoi(argv[2]);
	(*info)->time_eat = ft_atoi(argv[3]);
	(*info)->time_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		(*info)->n_eat = ft_atoi(argv[5]);
	if (argc == 4)
		(*info)->n_eat = -1;
	(*info)->forks = forks;
	(*info)->phils = phils;
	(*info)->threads = threads;
	pthread_mutex_init(&((*info)->print), NULL);
	init_info_sub2(info, ft_atoi(argv[1]));
}

void	init_info_sub1(
	t_fork **forks, t_phil **phils, pthread_t **threads, int n)
{
	make_forks(forks, n);
	make_phils(phils, n, forks);
	make_threads(threads, n);
}

void	init_info_sub2(t_info **info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((*info)->phils[i]).print = &((*info)->print);
		i++;
	}
}

void	free_info(t_info **info)
{
	free(*info);
}
