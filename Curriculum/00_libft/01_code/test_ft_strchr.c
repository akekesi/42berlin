/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:10:19 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 21:58:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_strchr(void)
{
	int		c;
	char	str[] = "012X45";
	char	*result;
	char	*result_ft;


	c = 'X';
	result = strchr(str, c);
	result_ft = ft_strchr(str, c);
	if (result !=result_ft)
	{
		printf("Error-1:\n");
		printf("result: %p\n", result);
		printf("result: %p\n", result_ft);
		return (0);
	}
	c = '!';
	result = strchr(str, c);
	result_ft = ft_strchr(str, c);
	if (result != result_ft)
	{
		printf("Error-2:\n");
		printf("result: %p\n", result);
		printf("result: %p\n", result_ft);
		return (0);
	}
	c = '\0';
	result = strchr(str, c);
	result_ft = ft_strchr(str, c);
	if (result != result_ft)
	{
		printf("Error-3:\n");
		printf("result: %p\n", result);
		printf("result: %p\n", result_ft);
		return (0);
	}
	c = '\0';
	str[0] = '\0';
	result = strchr(str, c);
	result_ft = ft_strchr(str, c);
	if (result != result_ft)
	{
		printf("Error-4:\n");
		printf("result: %p\n", result);
		printf("result: %p\n", result_ft);
		return (0);
	}
	return (1);
}
