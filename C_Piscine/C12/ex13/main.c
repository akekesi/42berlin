/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:07:22 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/28 11:07:22 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_print(t_list *begin_list)
{
	t_list	*elem;

	elem = begin_list;
	while (elem)
	{
		printf("%p --> %p\n", elem, elem->next);
		elem = elem->next;
	}
}

int	main(void)
{
	int		data1;
	int		data2;
	int		data3;
	int		data4;
	int		data5;
	int		data6;
	t_list	*elem0;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*elem6;
	t_list	**begin_list1;
	t_list	**begin_list2;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	data3 = 4;
	data3 = 5;
	data3 = 6;
	elem0 = NULL;
	elem1 = ft_create_elem(&data1);
	elem2 = ft_create_elem(&data2);
	elem3 = ft_create_elem(&data3);
	elem4 = ft_create_elem(&data4);
	elem5 = ft_create_elem(&data5);
	elem6 = ft_create_elem(&data6);
	begin_list1 = &elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	begin_list2 = &elem4;
	elem4->next = elem5;
	elem5->next = elem6;
	printf("list1:\n");
	ft_list_print(*begin_list1);
	printf("list2:\n");
	ft_list_print(*begin_list2);
	printf("---------------------------------------------\n");
	printf("list1 + list2:\n");
	ft_list_merge(begin_list1, *begin_list2);
	ft_list_print(*begin_list1);
	printf("---------------------------------------------\n");
	printf("list1 + NULL:\n");
	ft_list_merge(begin_list1, elem0);
	ft_list_print(*begin_list1);
	printf("---------------------------------------------\n");
	printf("NULL + list2:\n");
	ft_list_merge(&elem0, *begin_list2);
	ft_list_print(elem0);
	printf("---------------------------------------------\n");
	printf("NULL + NULL:\n");
	elem0 = NULL;
	ft_list_merge(&elem0, elem0);
	ft_list_print(elem0);
	printf("---------------------------------------------\n");
	printf("list1:\n");
	ft_list_print(*begin_list1);
	printf("list2:\n");
	ft_list_print(*begin_list2);

	// free !!!
}
