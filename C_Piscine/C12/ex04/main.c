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
	// <--- pointer to pointer ---|
	
	t_list	**begin_list;
	t_list	*elem1;
	void	*data;

	data = NULL;
	elem1 = NULL;
	begin_list = &elem1;	// Why does only this work?
	// *begin_list = elem1;	// Why does this not work?
	// *begin_list = NULL;	// Why does this not work?
	
	printf("\n0. empty:\n");
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
	
	printf("\n1. push back:\n");
	ft_list_push_back(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list) -> next);
	
	printf("\n2. push back:\n");
	ft_list_push_back(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list) -> next);
	printf("next next:      %p\n", ((*begin_list) -> next) -> next);

	printf("\n3. push back:\n");
	ft_list_push_back(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list) -> next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list) -> next);
	printf("next next:      %p\n", ((*begin_list) -> next) -> next);
	printf("next next next: %p\n", (((*begin_list) -> next) -> next) -> next);

	//  free !!!
}
