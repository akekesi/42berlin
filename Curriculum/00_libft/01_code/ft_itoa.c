/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:06:58 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 15:06:58 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

char		*ft_itoa(int n);
static int	hf_calc_digits(unsigned int n);
static int	hf_abs_int(int n);

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == INT_MIN)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	i = 0;
	if (n < 0)
		i++;
	n = hf_abs_int(n);
	i += hf_calc_digits(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (n)
	{
		str[i--] = '0' + n % 10;
		n /= 10;
	}
	if (!i)
		str[i] = '-';
	return (str);
}

static int	hf_abs_int(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static int	hf_calc_digits(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	main(void)
{
	int		n;
	char	*str;

	n = 0;
	n = 123;
	n = -123;
	n = 2147483647;
	n = -2147483648;
	str = ft_itoa(n);
	printf("n: %d\n", n);
	printf("n: %s\n", str);
}
