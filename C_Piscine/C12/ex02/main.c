/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:55:56 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 23:55:56 by akekesi          ###   ########.fr       */
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
	elem1 -> next = elem2;
	elem2 -> next = elem3;
	printf("size: %d\n", ft_list_size(elem1));
	printf("size: %d\n", ft_list_size(elem2));
	printf("size: %d\n", ft_list_size(elem3));
	printf("size: %d\n", ft_list_size(elem2));
	printf("size: %d\n", ft_list_size(elem1));
	printf("size: %d\n", ft_list_size(NULL));
}
