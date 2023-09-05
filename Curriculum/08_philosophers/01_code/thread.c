/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/05 21:07:32 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	int	i;

	i = 5;
	while (i-- > 0)
	{
		printf("-->%d\n", *(int *)arg);
		usleep(100);
	}
	return (NULL);
}

void	start_threads(pthread_t **threads, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		pthread_create(&(*threads)[i], NULL, routine, &i);
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
