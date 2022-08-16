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
	t_list	**begin_list;
	t_list	*elem;
	void	*data;

	data = NULL;
	elem = NULL;
	begin_list = &elem;

	printf("\n0. empty:\n");
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list)->next, *begin_list, begin_list, &begin_list);

	printf("\n1. push front:\n");
	ft_list_push_front(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list)->next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list)->next);

	printf("\n2. push front:\n");
	ft_list_push_front(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list)->next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list)->next);
	printf("next next:      %p\n", ((*begin_list)->next)->next);

	printf("\n3. push front:\n");
	ft_list_push_front(begin_list, data);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list)->next, *begin_list, begin_list, &begin_list);
	printf("next:           %p\n", (*begin_list)->next);
	printf("next next:      %p\n", ((*begin_list)->next)->next);
	printf("next next next: %p\n", (((*begin_list)->next)->next)->next);

	printf("\nFree:\n");
	ft_list_free(begin_list);
	printf("**begin_list:   %p <-- %p <-- %p <-- %p\n", &(*begin_list)->next, *begin_list, begin_list, &begin_list);
}
