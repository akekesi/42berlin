/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:25:58 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:07:13 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_memset(void)
{
	char	str[] = "12345";
	char	str_ft[] = "12345";
	int		c = 'X';
	size_t	n = 3;
	void	*result_memset;
	void	*result_ft_memset;

	printf("just one test (hard coded)\n");
	// printf("Enter a string, a character and a number to test ft_memset(): ");
	// scanf("%s  %c  %d", str, c, (size_t)n);
	// printf("%s, %c, %d", str, c, n);
	result_memset = memset(str, c, n);
	result_ft_memset = ft_memset(str_ft, c, n);
	if (strcmp(result_memset, result_ft_memset))
	{
		printf("Error:\n");
		printf("memset():    %s\n", result_memset);
		printf("ft_memset(): %s\n", result_ft_memset);
		return (0);
	}
	printf("result_memset:    %s\n", result_memset);
	printf("result_ft_memset: %s\n", result_ft_memset);
	return (1);
}
