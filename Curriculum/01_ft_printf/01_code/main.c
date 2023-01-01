/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:25:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 15:25:55 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	main(void)
{
	int	n;
	int	n___;

	n = 0;
	n___ = 0;
	// n___ = printf("-->% %<--\n");


	n = ft_printf("-->%3c<--\n", 'X');
	n___ = printf("-->%3c<--\n", 'X');
	printf("n: %d\n", n);
	printf("n: %d\n", n___);

	n = ft_printf("-->%-3c<--\n", 'X');
	n___ = printf("-->%-3c<--\n", 'X');
	printf("n: %d\n", n);
	printf("n: %d\n", n___);

	// n = ft_printf("-->%-0123456789.# +c%%_%_%_%%%<--\n", 'X');
	// n___ = printf("-->X%%_%%_%%_%%%%<--\n");
	// printf("n: %d\n", n);
	// printf("n: %d\n", n___);

	// printf("-->%s<--\n", ft_get_types());
	// printf("-->%s<--\n", ft_get_flags());
	// printf("-->%s<--\n", ft_get_null('s'));
	// printf("-->%s<--\n", ft_get_null('p'));
	// printf("-->%s<--\n", ft_get_null('?'));
	return (0);
}
