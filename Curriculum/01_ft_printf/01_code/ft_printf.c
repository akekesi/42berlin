/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:31:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/27 23:04:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"

int		ft_printf(const char *str, ...);
char	*ft_types(void);
int		ft_check_next(const char *str);
int		ft_char_in_str(char c, char *str);
int		ft_strlen(const char *str);

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	printf("%s --> %d\n", str, ft_strlen(str));
	while (str[i])
	{
		printf("%d. ", i);
		if (str[i] == '%' && ft_check_next(&str[i]))
		{
			i++;
			printf("--> %c --> %d\n", str[i], va_arg(args, int));
		}
		else
			printf("%c\n", str[i]);
		i++;
	}
	va_end(args);
}

char	*ft_types(void)
{
	return ("cspdiuxX%");
}

int	ft_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_next(const char *str)
{
	return (ft_char_in_str(*(++str), ft_types()));
}

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
