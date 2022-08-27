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

int	main(void)
{
	int		data1;
	int		data2;
	int		data3;
	int		data_ref;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem_return;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	elem1 = ft_create_elem(&data1);
	elem2 = ft_create_elem(&data2);
	elem3 = ft_create_elem(&data3);
	elem1->next = elem2;
	elem2->next = elem3;
	printf("%p\n", elem1);
	printf("%p\n", elem2);
	printf("%p\n", elem3);
	printf("---------------------------------------------\n");
	printf("test with begin_list = NULL:\n");
	elem_return = ft_list_find(NULL, (void *) &data_ref, ft_cmp);
	printf("%p\n", elem_return);
	printf("---------------------------------------------\n");
	printf("test with list (find):\n");
	data_ref = data2;
	elem_return = ft_list_find(elem1, (void *) &data_ref, ft_cmp);
	printf("%p\n", elem_return);
	printf("---------------------------------------------\n");
	printf("test with list (not find):\n");
	data_ref = 99;
	elem_return = ft_list_find(elem1, (void *) &data_ref, ft_cmp);
	printf("%p\n", elem_return);
	printf("---------------------------------------------\n");
}
