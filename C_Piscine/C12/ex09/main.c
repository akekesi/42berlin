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
	printf("data: %d\n", 111 + *(int *) arg);
}

void	ft_do_something_elem(void *arg)
{
	printf("data: %d\n", 111 + *(int *) ((t_list *) arg)->data);
}

int		main(void)
{
	int		data1;
	int		data2;
	int		data3;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	elem1 = ft_create_elem(&data1);
	elem2 = ft_create_elem(&data2);
	elem3 = ft_create_elem(&data3);
	elem1->next = elem2;
	elem2->next = elem3;
	ft_list_foreach(elem1, ft_do_something);
	printf("\n");
	ft_list_foreach_elem(elem1, ft_do_something_elem);	
}
