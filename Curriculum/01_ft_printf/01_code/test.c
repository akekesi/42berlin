/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:46:45 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 20:46:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_check(int n, int n___)
{
	if (n == n___)
	{
		printf("OK ");
		test_print(n, n___, '=');
		return (1);
	}
	printf("NOK ");
	test_print(n, n___, '!');
	printf("^^^ ERROR^^^\n");
	return (0);
}

void	test_print(int n, int n___, int c)
{
	printf("%d %c= %d\n", n, c, n___);
}

