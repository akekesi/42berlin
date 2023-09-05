/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:03:14 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/05 20:11:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_forks(t_fork **forks, unsigned int n)
{
	unsigned int	i;

	*forks = (t_fork *)malloc(sizeof(t_fork) * n);
	if (!(*forks))
		return ;
	i = 0;
	while (i < n)
	{
		(*forks)[i].free = 1;
		pthread_mutex_init(&((*forks)[i].lock), NULL);
		i++;
	}
}

void	free_forks(t_fork **forks, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&((*forks)[i].lock));
		i++;
	}
	free(*forks);
}
