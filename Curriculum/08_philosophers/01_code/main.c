/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 17:38:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	t_info	*info;

	info = NULL;
	n = ft_atoi(argv[1]);
	init_info(argc, argv, &info);
	printf("info-n: %d\n", info->n);
	i = 0;
	while (i < n)
	{
		printf("fork-%d: %p\n", i, &(info->forks[i]));
		printf("phil-%d: %p\n", i, &(info->phils[i]));
		printf("        %p\n", info->phils[i].left);
		printf("        %p\n", info->phils[i].right);
		i++;
	}
	start_threads(&(info->threads), n, &(info->phils));
	join_threads(&(info->threads), n);
	free_forks(&(info->forks), n);
	free_phils(&(info->phils));
	free_threads(&(info->threads));
	free_info(&info);
}
