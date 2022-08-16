/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:35:02 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 19:35:02 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		i_max;
	t_list	**begin_list;
	t_list	*elem1;
	t_list	*elem_nbr;
	void	*data;

	i_max = 3;
	data = NULL;
	elem1 = NULL;
	begin_list = &elem1;

	i = 0;
	ft_list_print(*begin_list);
	printf("---------------------------------------------\n");
	while (i < i_max)
	{
		ft_list_push_back(begin_list, data);
		i++;
	}
	ft_list_print(*begin_list);
	printf("---------------------------------------------\n");
	i = 0;
	while (i < i_max)
	{
		elem_nbr = ft_list_at(*begin_list, i);
		printf("elem_%d: %p\n", i, elem_nbr);
		i++;
	}	
	printf("---------------------------------------------\n");
	ft_list_print(*begin_list);

	// free !!!
}
