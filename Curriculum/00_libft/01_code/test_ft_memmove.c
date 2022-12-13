/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:43:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:11:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_memmove(void)
{
	const char	src[] = "123";
	char	dest[] = "XXXXX";
	char	dest_ft[] = "XXXXX";
	size_t	n = 3;
	void	*result_memmove;
	void	*result_ft_memmove;

	result_memmove = memmove(dest, src, n);
	result_ft_memmove = ft_memmove(dest_ft, src, n);
	if (strcmp(result_memmove, result_ft_memmove))
	{
		printf("Error:\n");
		printf("memmove():    %s\n", result_memmove);
		printf("ft_memmove(): %s\n", result_ft_memmove);
		return (0);
	}
	printf("dest:    %s\n", dest);
	printf("dest_ft: %s\n", dest_ft);
	return (1);
}
