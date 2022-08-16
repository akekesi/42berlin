/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:18:36 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 18:18:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*elem;
	void	*data;

	data = NULL;
	elem = ft_create_elem(data);
	printf("elem: %p\n", elem);
	printf("elem->next: %p\n", elem->next);
	printf("elem->data: %p\n", elem->data);
	free(elem);
	elem = NULL;
	printf("elem: %p\n", elem);
	return (0);
}
