/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/06 18:40:30 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_threads(pthread_t **threads, int n)
{
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if (!(*threads))
		return ;
}

void	free_threads(pthread_t **threads)
{
	free(*threads);
}

void	start_threads(t_info **info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_create(
			&((*info)->threads)[i], NULL, routine, &((*info)->phils)[i]);
		i++;
	}
}

void	join_threads(pthread_t **threads, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join((*threads)[i], NULL);
		i++;
	}
}
