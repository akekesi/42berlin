/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:45:09 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/17 18:45:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_do_something(void *arg)
{
	printf("data: %d\n", 100 + *(int *) arg);
}

int	ft_cmp(void *data, void *data_ref)
{
	if (*(int *) data == *(int *) data_ref)
		return (0);
	return (1);
}

int	main(void)
{
	int		data1;
	int		data2;
	int		data3;
	int		data_ref;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	data_ref = data2;
	elem1 = ft_create_elem(&data1);
	elem2 = ft_create_elem(&data2);
	elem3 = ft_create_elem(&data3);
	elem1->next = elem2;
	elem2->next = elem3;
	printf("---------------------------------------------\n");
	printf("test with begin_list = NULL:\n");
	ft_list_foreach_if(NULL, ft_do_something, (void *) &data_ref, ft_cmp);
	printf("---------------------------------------------\n");
	printf("test with list:\n");
	ft_do_something((void *) &data_ref);
	ft_list_foreach_if(elem1, ft_do_something, (void *) &data_ref, ft_cmp);
	printf("---------------------------------------------\n");
}
