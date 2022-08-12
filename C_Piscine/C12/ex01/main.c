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
	// |--- pointer to pointer --->
	int	n;
	int	*p_n;
	int	**pp_n;

	n = 13;
	p_n = &n;
	pp_n = &p_n;

	printf("n:    %d <-- %p\n", n, &n);
	printf("p_n:  %d <-- %p <-- %p\n", *p_n, p_n, &p_n);
	printf("pp_n: %d <-- %p <-- %p <-- %p\n", **pp_n, *pp_n, pp_n, &pp_n);
	printf("\n");
	// <--- pointer to pointer ---|
	
	t_list	**begin_list;
	t_list	*elem1;
	void	*data;

	data = NULL;
	elem1 = ft_create_elem(data);
	begin_list = &elem1;
	
	printf("*elem1:        %p <-- %p <-- %p \n", &elem1->next, elem1, &elem1);
	printf("**beginn_list: %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
	
	ft_list_push_front(begin_list, data);
	printf("**beginn_list: %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);

	free(elem1);
	elem1 = NULL;
	printf("*elem1:        %p <-- %p <-- %p \n", &elem1->next, elem1, &elem1);
	printf("**beginn_list: %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
}
