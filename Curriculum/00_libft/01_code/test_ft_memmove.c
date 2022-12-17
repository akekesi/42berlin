/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:43:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/17 19:57:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_memmove(void)
{
	const char	src[] = "123456";
	const char	src_ft[] = "123456";
	char	*dest;
	char	*dest_ft;
	size_t	n;
	int		i;
	void	*result_memmove;
	void	*result_ft_memmove;

	n = 3;
	i = 2;
	dest = (char *) src + i;
	dest_ft = (char *) src_ft + i;
	printf("dest:    %s\n", dest);
	printf("dest_ft: %s\n", dest_ft);
	printf("src:     %s\n", src);
	result_memmove = memmove(dest, src, n);
	result_ft_memmove = ft_memmove(dest_ft, src_ft, n);
	printf("memmove():    %s\n", result_memmove);
	printf("ft_memmove(): %s\n", result_ft_memmove);
	if (strcmp(result_memmove, result_ft_memmove))
	{
		printf("Error:\n");
		printf("memmove():    %s\n", result_memmove);
		printf("ft_memmove(): %s\n", result_ft_memmove);
		return (0);
	}
	return (1);
}
