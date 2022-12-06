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
#include <ctype.h>
#include "libft.h"

int	test_ft_isalpha(void);

int	main(int argc, char **argv)
{
	char	*c;
	int		result_isalpha;
	int		result_ft_isalpha;

	if (test_ft_isalpha())
		printf("test_ft_isalpha(): OK\n");
	else
		printf("test_ft_isalpha(): NOT OK\n");
}
