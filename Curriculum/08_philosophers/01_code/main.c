/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 20:03:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int			i;
	int			n;
	t_info		*info;
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	info = NULL;
	forks = NULL;
	phils = NULL;
	threads = NULL;

	n = ft_atoi(argv[1]);

	make_info(&info, n);
	make_forks(&forks, n);
	make_phils_sub1(&phils, argc, argv);
	make_phils_sub2(&phils, &info, &forks, n);
	make_threads(&threads, n);

	i = 0;
	while (i < n)
	{
		printf("fork-%d: %p\n", i, &(forks[i]));
		printf("phil-%d: %p\n", i, &(phils[i]));
		printf("        %p\n", phils[i].left);
		printf("        %p\n", phils[i].right);
		i++;
	}
	start_threads(&threads, n, &phils);
	join_threads(&threads, n);
	free_forks(&forks, n);
	free_phils(&phils);
	free_threads(&threads);
}
