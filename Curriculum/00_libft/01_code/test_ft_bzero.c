/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:11 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/12 11:12:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

int	test_ft_bzero(void)
{
	char	str[] = "12345";
	char	str_ft[] = "12345";
	int		c = '\0';
	size_t	n = 1;

	printf("just one test (hard coded)\n");
	// printf("Enter a string and a number to test ft_bzero(): ");
	// scanf("%s %d", str, (size_t)n);
	// printf("%s, %d", str, n);
	memset(str, c, n); // bzero(str, n);
	ft_bzero(str_ft, n);
	if (strcmp(str, str_ft))
	{
		printf("Error:\n");
		printf("bzero():    %s\n", str);
		printf("ft_bzero(): %s\n", str_ft);
		return (0);
	}
	printf("str:    %s\n", str);
	printf("str_ft: %s\n", str_ft);
	return (1);
}
