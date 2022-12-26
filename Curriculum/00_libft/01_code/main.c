/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:55:11 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 00:19:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	printf("--> main test started <--\n");
	if (test_ft_isalpha())
		printf("test_ft_isalpha(): OK!\n");
	else
		printf("test_ft_isalpha(): NOT OK!\n");

	if (test_ft_isdigit())
		printf("test_ft_isdigit(): OK!\n");
	else
		printf("test_ft_isdigit(): NOT OK!\n");

	if (test_ft_isalnum())
		printf("test_ft_isalnum(): OK!\n");
	else
		printf("test_ft_isalnum(): NOT OK!\n");

	if (test_ft_isascii())
		printf("test_ft_isascii(): OK!\n");
	else
		printf("test_ft_isascii(): NOT OK!\n");

	if (test_ft_isprint())
		printf("test_ft_isprint(): OK!\n");
	else
		printf("test_ft_isprint(): NOT OK!\n");

	if (test_ft_strlen())
		printf("test_ft_strlen(): OK!\n");
	else
		printf("test_ft_strlen(): NOT OK!\n");

	if (test_ft_memset())
		printf("test_ft_memset(): OK!\n");
	else
		printf("test_ft_memset(): NOT OK!\n");

	if (test_ft_bzero())
		printf("test_ft_bzero(): OK!\n");
	else
		printf("test_ft_bzero(): NOT OK!\n");

	if (test_ft_memcpy())
		printf("test_ft_memcpy(): OK!\n");
	else
		printf("test_ft_memcpy(): NOT OK!\n");

	if (test_ft_memmove())
		printf("test_ft_memmove(): OK!\n");
	else
		printf("test_ft_memmove(): NOT OK!\n");

	if (test_ft_strlcpy())
		printf("test_ft_strlcpy(): OK!\n");
	else
		printf("test_ft_strlcpy(): NOT OK!\n");

	if (test_ft_strlcat())
		printf("test_ft_strlcat(): OK!\n");
	else
		printf("test_ft_strlcat(): NOT OK!\n");

	if (test_ft_toupper())
		printf("test_ft_toupper(): OK!\n");
	else
		printf("test_ft_toupper(): NOT OK!\n");

	if (test_ft_tolower())
		printf("test_ft_tolower(): OK!\n");
	else
		printf("test_ft_tolower(): NOT OK!\n");

	if (test_ft_strchr())
		printf("test_ft_strchr(): OK!\n");
	else
		printf("test_ft_strchr(): NOT OK!\n");

	if (test_ft_strrchr())
		printf("test_ft_strrchr(): OK!\n");
	else
		printf("test_ft_strrchr(): NOT OK!\n");

	if (test_ft_strncmp())
		printf("test_ft_strncmp(): OK!\n");
	else
		printf("test_ft_strncmp(): NOT OK!\n");

	if (test_ft_memchr())
		printf("test_ft_memchr(): OK!\n");
	else
		printf("test_ft_memchr(): NOT OK!\n");

	if (test_ft_memcmp())
		printf("test_ft_memcmp(): OK!\n");
	else
		printf("test_ft_memcmp(): NOT OK!\n");

	if (test_ft_strnstr())
		printf("test_ft_strnstr(): OK!\n");
	else
		printf("test_ft_strnstr(): NOT OK!\n");

	if (test_ft_atoi())
		printf("test_ft_atoi(): OK!\n");
	else
		printf("test_ft_atoi(): NOT OK!\n");

	if (test_ft_calloc())
		printf("test_ft_calloc(): OK!\n");
	else
		printf("test_ft_calloc(): NOT OK!\n");

	if (test_ft_strdup())
		printf("test_ft_strdup(): OK!\n");
	else
		printf("test_ft_strdup(): NOT OK!\n");

	if (test_ft_substr())
		printf("test_ft_substr(): OK!\n");
	else
		printf("test_ft_substr(): NOT OK!\n");

	if (test_ft_strjoin())
		printf("test_ft_strjoin(): OK!\n");
	else
		printf("test_ft_strjoin(): NOT OK!\n");

	if (test_ft_strtrim())
		printf("test_ft_strtrim(): OK!\n");
	else
		printf("test_ft_strtrim(): NOT OK!\n");

	if (test_ft_split())
		printf("test_ft_split(): OK!\n");
	else
		printf("test_ft_split(): NOT OK!\n");

	if (test_ft_itoa())
		printf("test_ft_itoa(): OK!\n");
	else
		printf("test_ft_itoa(): NOT OK!\n");

	if (test_ft_strmapi())
		printf("test_ft_strmapi(): OK!\n");
	else
		printf("test_ft_strmapi(): NOT OK!\n");

	if (test_ft_striteri())
		printf("test_ft_striteri(): OK!\n");
	else
		printf("test_ft_striteri(): NOT OK!\n");
	
	if (test_ft_putchar_fd())
		printf("test_ft_putchar_fd(): OK!\n");
	else
		printf("test_ft_putchar_fd(): NOT OK!\n");
	
	if (test_ft_putstr_fd())
		printf("test_ft_putstr_fd(): OK!\n");
	else
		printf("test_ft_putstr_fd(): NOT OK!\n");
	
	if (test_ft_putendl_fd())
		printf("test_ft_putendl_fd(): OK!\n");
	else
		printf("test_ft_putendl_fd(): NOT OK!\n");
	
	if (test_ft_putnbr_fd())
		printf("test_ft_putnbr_fd(): OK!\n");
	else
		printf("test_ft_putnbr_fd(): NOT OK!\n");

	printf("no tets for bonus part yet\n");

	printf("--> main test finished <--\n");
	return (0);
}
