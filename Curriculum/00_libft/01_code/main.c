/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:55:11 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/05 09:55:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	test_ft_isalpha(void);

int	main(void)
{
	if (test_ft_isalpha())
		printf("test_ft_isalpha(): OK\n");
	else
		printf("test_ft_isalpha(): NOT OK\n");
}
