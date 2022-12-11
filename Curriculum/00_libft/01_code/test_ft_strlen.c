/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:03 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 19:22:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "test.h"

int	test_ft_strlen(void)
{
	const char	str[111];
	size_t		result_strlen;
	size_t		result_ft_strlen;

	printf("Enter a string to test ft_strlen(): ");
	scanf("%s", str);
	result_strlen = strlen(str);
	result_ft_strlen = ft_strlen(str);
	if (result_strlen != result_ft_strlen)
	{
		printf("Error:\n");
		printf("strlen(%s):    %d\n", str, result_strlen);
		printf("ft_strlen(%s): %d\n", str, result_ft_strlen);
		return (0);
	}
	return (1);
}
