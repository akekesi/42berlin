/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:43:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/12 11:43:26 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "test.h"

int	test_ft_memcpy(void)
{
	const char	src[] = "123";
	char	dest[] = "XXXXX";
	char	dest_ft[] = "XXXXX";
	size_t	n = 5;
	void	*result_memcpy;
	void	*result_ft_memcpy;

	result_memcpy = memcpy(dest, src, n);
	result_ft_memcpy = ft_memcpy(dest_ft, src, n);
	if (strcmp(result_memcpy, result_ft_memcpy))
	{
		printf("Error:\n");
		printf("memcpy():    %s\n", result_memcpy);
		printf("ft_memcpy(): %s\n", result_ft_memcpy);
		return (0);
	}
	printf("dest:    %s\n", dest);
	printf("dest_ft: %s\n", dest_ft);
	return (1);
}
