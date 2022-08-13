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

int	main(int argc, char **argv)
{
	int		size;
	char	**strs;
	t_list	*elem;
	t_list	*elem_next;

	size = --argc;
	strs = ++argv;

	elem = ft_list_push_strs(size, strs);
	if (size == 0)
		printf("*elem-%d:  %p --> %p\n", size, &elem, elem);
	else
	{
		while (size)
		{
			elem_next = elem -> next;
			printf("*elem-%d:  %p --> %p --> %p --> %s\n", size, &elem, elem, elem_next, (char *) elem -> data);
			elem = elem_next;
			size--;
		}
	}

	//  free !!!
}
