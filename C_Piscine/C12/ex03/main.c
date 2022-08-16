/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:36:09 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/13 09:36:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	void	*data;

	data = NULL;
	elem1 = ft_create_elem(data);
	elem2 = ft_create_elem(data);
	elem3 = ft_create_elem(data);
	elem1->next = elem2;
	elem2->next = elem3;
	printf("elem1: %p\n", elem1);
	printf("elem2: %p\n", elem2);
	printf("elem3: %p\n", elem3);
	printf("last:  %p\n", ft_list_last(elem1));
	printf("last:  %p\n", ft_list_last(elem2));
	printf("last:  %p\n", ft_list_last(elem3));
	printf("last:  %p\n", ft_list_last(elem2));
	printf("last:  %p\n", ft_list_last(elem1));
	printf("last:  %p\n", ft_list_last(NULL));

	free(elem1);
	elem1 = NULL;
	free(elem2);
	elem2  = NULL;
	free(elem3);
	elem3 = NULL;
}
