/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/05 23:23:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	int	i;

	i = 5;
	while (i-- > 0)
	{
		printf("-->%d/%d\n", ((t_phil *)arg)->n, i);
		usleep(1000000);
	}
	return (NULL);
}

void	start_threads(pthread_t **threads, unsigned int n, t_phil **phils)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		pthread_create(&(*threads)[i], NULL, routine, &(*phils)[i]);
		i++;
	}
}

void	join_threads(pthread_t **threads, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		pthread_join((*threads)[i], NULL);
		i++;
	}
}

void	make_threads(pthread_t **threads, unsigned int n)
{
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if (!(*threads))
		return ;
}

void	free_threads(pthread_t **threads)
{
	free(*threads);
}
