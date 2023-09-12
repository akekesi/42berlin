/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/12 23:04:50 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int			n;
	t_info		*info;
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	if (!check_args(argc, argv))
		return (0);
	info = NULL;
	forks = NULL;
	phils = NULL;
	threads = NULL;
	n = ft_atoi(argv[1]);
	make_info(&info);
	make_forks(&forks, n);
	make_phils_sub1(&phils, argc, argv);
	make_phils_sub2(&phils, &info, &forks, n);
	make_threads(&threads, n);
	printf("Syncronization of Threads\n");
	start_threads(&threads, n, &phils);
	join_threads(&threads, n);
	free_forks(&forks, n);
	free_phils(&phils);
	free_threads(&threads);
	free_info(&info);
}
