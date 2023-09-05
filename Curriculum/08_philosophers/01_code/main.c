/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/05 20:13:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	n;
	t_fork			*forks;
	t_phil			*phils;

	forks = NULL;
	phils = NULL;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		make_forks(&forks, n);
		make_phils(&phils, n, &forks);
		i = 0;
		while (i < n)
		{
			printf("fork-%d: %p\n", i, &(forks[i]));
			printf("phil-%d: %p\n", i, &(phils[i]));
			printf("        %p\n", phils[i].left);
			printf("        %p\n", phils[i].right);
			i++;
		}
		free_forks(&forks, n);
		free_phils(&phils);
	}
}
