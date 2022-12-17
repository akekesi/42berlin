/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:43:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/17 19:58:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_memcpy(void)
{
	const char	src[] = "123456";
	const char	src_ft[] = "123456";
	char	*dest;
	char	*dest_ft;
	size_t	n;
	int		i;
	void	*result_memcpy;
	void	*result_ft_memcpy;

	n = 3;
	i = 3;
	dest = (char *) src + i;
	dest_ft = (char *) src_ft + i;
	printf("dest:    %s\n", dest);
	printf("dest_ft: %s\n", dest_ft);
	printf("src:     %s\n", src);
	result_memcpy = memcpy(dest, src, n);
	result_ft_memcpy = ft_memcpy(dest_ft, src_ft, n);
	printf("memcpy():    %s\n", result_memcpy);
	printf("ft_memcpy(): %s\n", result_ft_memcpy);
	if (strcmp(result_memcpy, result_ft_memcpy))
	{
		printf("Error:\n");
		printf("memcpy():    %s\n", result_memcpy);
		printf("ft_memcpy(): %s\n", result_ft_memcpy);
		return (0);
	}
	return (1);
}
