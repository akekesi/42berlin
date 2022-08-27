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

int	ft_cmp(void *data, void *data_ref)
{
	if (*(int *) data == *(int *) data_ref)
		return (0);
	return (1);
}

void	ft_list_print(t_list **begin_list)
{
	t_list	*elem;

	elem = *begin_list;
	while (elem)
	{
		printf("data=%d, %p --> %p\n", *(int *) elem->data, elem, elem->next);
		elem = elem->next;
	}
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
	t_list	**begin_list;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	elem1 = ft_create_elem(&data1);
	elem2 = ft_create_elem(&data2);
	elem3 = ft_create_elem(&data3);
	begin_list = &elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	ft_list_print(begin_list);
	printf("---------------------------------------------\n");
	data_ref = data1;
	// data_ref = 99;
	printf("test with data_ref=%d:\n", data_ref);
	ft_list_remove_if(begin_list, (void *) &data_ref, ft_cmp, free);
	ft_list_print(begin_list);
	ft_list_remove_if(begin_list, (void *) &data2, ft_cmp, free);
	ft_list_print(begin_list);
	ft_list_remove_if(begin_list, (void *) &data3, ft_cmp, free);
	ft_list_print(begin_list);
	ft_list_remove_if(begin_list, (void *) &data3, ft_cmp, free);
	ft_list_print(begin_list);
	printf("---------------------------------------------\n");
}
